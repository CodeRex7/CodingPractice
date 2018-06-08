#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
void solve(vector<int> arr, int money) {
    
    /*for(int i=0;i<arr.size();i++){
        int temp=arr[i];
        arr[i]=0;
        int x=find(arr.begin(),arr.end(),money-temp)-arr.begin();
        if(arr[x]+temp<=money)
        {
            cout<<i+1<<" "<<x+1<<endl;
            break;
        }
        arr[i]=temp;
    }*/
    map<int,int>m;
    for(int i=0;i<arr.size();i++){
        if(m.find(arr[i])==m.end()){
        m.insert(make_pair(arr[i],i+1));//Inserting only one the number is not in the map
        }
        else{
            m[arr[i]]=i+1; // just upadating the value without inserting.. hence no duplicacy of data
        }
    }
    int rear=0,front=0;
    for(int i=0;i<arr.size();i++){
        rear=i+1;
        int k=money-arr[i];
        if(m.find(k)!=m.end()){
            front=m[k];
            break;
        }
    }
    cout<<rear<<" "<<front<<endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        solve(arr, money);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
