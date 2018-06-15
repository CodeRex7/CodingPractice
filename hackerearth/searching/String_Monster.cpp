#include <bits/stdc++.h>
using namespace std;

struct Word {
    int freq[26];
 
    Word(int fr[26]){
        for(int i=0;i<26;i++)
            freq[i] = fr[i];
    }
    
    Word(string s=""){
        for(int i=0;i<26;i++)
            freq[i] = 0;
        for(int i=0;i<s.length();i++)
            freq[(int)(s[i]-'a')]++;
    }

    Word operator-(const Word &w){
        int fr[26];
        for(int i=0;i<26;i++) 
            fr[i] = freq[i]-w.freq[i];
    return Word(fr);
    }
    bool operator==(const Word &w) {
        for(int i=0;i<26;i++)
            if(freq[i] != w.freq[i])
                return false;
        return true;
    }
};
 
bool check(Word X, Word list[], int n){
    if(n == 0) {
    if(X == Word(""))
        return true;
    else
        return false;
    }
    for(int i=0;i<26;i++)
        if(X.freq[i] < 0)
            return false;
    return check(X, list, n-1) || check(X-list[n-1], list, n-1);
}
 
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Word list[n];
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            list[i] = Word(s);
        }
        string x;
        cin >> x;
        Word X(x);
        if(check(X, list, n)) 
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}