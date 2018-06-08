#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector< pair<int,int> >arr(1000001);
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            arr[a].first++;
            arr[a].second=a;
        }
        sort(arr.begin(),arr.end());
        int flag=0;
        int k=1000000,j=0;
        for(;k>0;){
            if(arr[j].first==0)
                {j++;}
            else if(arr[k].second-arr[j].second>0)
                {cout<<arr[k].first-arr[j].first<<endl;flag=1;break;}
            else
                k--;
        }
        if(!flag){
            cout<<"-1"<<endl;
        }
    }
    return 0;
}
