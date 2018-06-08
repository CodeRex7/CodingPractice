#include <bits/stdc++.h>

using namespace std;
// max heap to store the higher half elements 
priority_queue<int> max_heap_left;
 
// min heap to store the lower half elements
priority_queue<int,vector<int>,greater<int>> min_heap_right;
 
// function to calculate median of stream 
void calculate_median(double x,double &median)
{
   
    if (max_heap_left.size() > min_heap_right.size())
    {
        if (x < median)
        {
            min_heap_right.push(max_heap_left.top());
            max_heap_left.pop();
            max_heap_left.push(x);
        }
        else
            min_heap_right.push(x);
 
        median = ((double)max_heap_left.top()
                +(double)min_heap_right.top())/2.0;
    }
 
    // case2(both heaps are balanced)
    else if (max_heap_left.size()==min_heap_right.size())
    {
        if (x < median)
        {
            max_heap_left.push(x);
            median = (double)max_heap_left.top();
        }
        else
        {
            min_heap_right.push(x);
            median = (double)min_heap_right.top();
        }
    }
 
    // case3(right side heap has more elements)
    else
    {
        if (x > median)
        {
            max_heap_left.push(min_heap_right.top());
            min_heap_right.pop();
            min_heap_right.push(x);
        }
        else
            max_heap_left.push(x);
 
        median = ((double)max_heap_left.top()
                 + (double)min_heap_right.top())/2.0;
    }
}


int main()
{
    int n;
    cin >> n;
    double median = 0;//stores the median
    vector<int>a(n);

    for (int i = 0; i < n; i++) {
        cin>>a[i];
        // calculating new median for each 
        // new element added to the stream
        calculate_median(a[i], median);
        cout << setprecision(1) << fixed << median << endl;
    }

    return 0;
}
