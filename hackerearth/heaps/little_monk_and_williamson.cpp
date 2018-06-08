#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
 
int main(){
    int q;
    cin>>q;
    map<ll,ll>count;
    priority_queue<ll>max;
    priority_queue<ll, vector<ll>, greater<ll> >min;
    while(q--){
        string n;
        cin>>n;
        if(n=="Push"){
            int num;
            cin>>num;
            count[num]++;
            max.push(num);
            min.push(num);
        }else if(n=="Diff"){
             while(!max.empty() && count[max.top()]==0)
                max.pop();
            
            while(!min.empty() && count[min.top()]==0)
                min.pop();
            
            
            if(max.empty()|| min.empty())
                cout<<"-1"<<endl;
            else{ 
                if(max.top() == min.top()){
                    count[max.top()]--;
                }
                else if(max.top() != min.top()){
                    count[max.top()]--;
                    count[min.top()]--;
                }
                cout<<max.top() - min.top()<<endl;
            }
        }else if(n=="CountHigh"){
            while(!max.empty() && count[max.top()]==0)
                max.pop();
            if(max.empty())
                cout<<"-1"<<endl;
            else
                cout<<count[max.top()]<<endl;
            
        }else if(n=="CountLow"){
            while(!min.empty() && count[min.top()]==0)
                min.pop();
            if(min.empty())
                cout<<"-1"<<endl;
            else
                cout<<count[min.top()]<<endl;
            
        }
    }
    return 0;
}
