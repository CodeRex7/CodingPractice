#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

ll mergeHalves(vector<ll>&arr,vector<ll>&temp,ll leftStart,ll rightEnd,ll count){
    ll leftEnd=(leftStart+rightEnd)/2;
    ll rightStart=leftEnd+1;
    ll left=leftStart;
    ll right=rightStart;
    ll index=leftStart;
    
    while(left<=leftEnd && right<=rightEnd){
        if(arr[left] <= arr[right]){
            temp[index]=arr[left];
            left++;
        }else{
            temp[index]=arr[right];
            right++;
            count+=leftEnd-left+1;
            //cout<<count<<endl;
        }
        index++;
        
    }
    for(ll i=left;i<=leftEnd;i++){
        temp[index++]=arr[i];
    }
    for(ll i=right;i<=rightEnd;i++){
        temp[index++]=arr[i];
    }
    for(ll i=leftStart;i<=rightEnd;i++){
        arr[i]=temp[i];
    }
    //cout<<count<<endl;
    return count;
    
}



ll mergeSort(vector<ll>&arr,vector<ll>&temp,ll leftStart, ll rightEnd,ll count){
    if(leftStart<rightEnd){
        ll middle=(leftStart+rightEnd)/2;
        count=mergeSort(arr,temp,leftStart,middle,count);
        count=mergeSort(arr,temp,middle+1,rightEnd,count);
        count=mergeHalves(arr,temp,leftStart,rightEnd,count);
    }
    //cout<<"hi"<<count<<endl;
    return count;
}

// Complete the countInversions function below.
ll countInversions(vector <ll> arr) {
    vector<ll>temp(arr.size());
    ll count=0;
    count =mergeSort(arr,temp,0,arr.size()-1,count);
    return count;
}



int main()
{
    ll t;
    cin >> t;
    
    for (ll t_itr = 0; t_itr < t; t_itr++) {
        ll n;
        cin >> n;

        vector<ll> arr(n);

        for (ll i = 0; i < n; i++) {
            cin>>arr[i];
        }

        ll result = countInversions(arr);
        cout << result << "\n";
    }

    return 0;
}
