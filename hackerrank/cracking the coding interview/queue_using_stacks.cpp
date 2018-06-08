#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest, stack_oldest;   
        void push(int x) {
            stack_oldest.push(x);
        }

        void pop() {
            if(stack_newest.empty()){
                while(!stack_oldest.empty()){
                    int q=stack_oldest.top();
                    stack_oldest.pop();
                    stack_newest.push(q);
            }
        }
        stack_newest.pop();
        }

        int front() {
             if(stack_newest.empty()){
                while(!stack_oldest.empty()){
                    int q=stack_oldest.top();
                    stack_oldest.pop();
                    stack_newest.push(q);
            }
            }
            int d=stack_newest.top();
            return d;
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}