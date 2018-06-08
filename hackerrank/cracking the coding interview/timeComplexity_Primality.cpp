#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
bool check(int a){
    if (a <= 1)  return false;
    if (a <= 3)  return true;
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0)
            return 0;
    }
    return 1;
}

int main(){
    int p;
    cin >> p;
    for(int a0 = 0; a0 < p; a0++){
        int n;
        cin >> n;
        bool a=check(n);
        if(a)
            cout<<"Prime"<<endl;
        else
            cout<<"Not prime"<<endl;
    }
    return 0;
}