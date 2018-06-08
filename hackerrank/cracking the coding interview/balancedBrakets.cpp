#include <bits/stdc++.h>

using namespace std;
/*void showstack(stack <char> gq)
{
    stack <char> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}*/


int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string expression;
        getline(cin, expression);
        int flag=0;
        stack <char> q;
        if(expression.size()%2==0){
        for(int i=0;i<expression.size();i++){
            char ch;
            
            switch(expression[i]){
                case '{':
                    q.push('{');
                        break;
                case '[':
                    q.push('[');
                        break;
                case '(':
                        q.push('(');
                        break;
                case '}':
      //                  showstack(q);
                        if(q.empty())
                           {flag=1;break;}
                        ch=q.top();
                        q.pop();
                        if(ch!='{')
                            flag=1;
                        break;
                case ']':
        //                showstack(q);
                        if(q.empty())
                        {flag=1;break;}
                        ch=q.top();
                        q.pop();
                        if(ch!='[')
                            flag=1;
                        break;
                case ')':
          //              showstack(q);
                        if(q.empty())
                        {flag=1;break;}
                        ch=q.top();
                        q.pop();
                        if(ch!='(')
                            flag=1;
                        break;
            }
            if(flag==1)
            {
                cout<<"NO"<<endl;
                break;
            }       
        }
        if(!q.empty() && flag==0)
            cout<<"NO"<<endl;
        else if(flag==0 && q.empty())
            cout<<"YES"<<endl;
        }
        else
            cout<<"NO"<<endl;
    } 
    return 0;
}
