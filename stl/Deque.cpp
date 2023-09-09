#include <bits/stdc++.h>

using namespace std;

int main()
{

    cout<<"Deque\n\n";
    
    deque<int> d;
    d.push_back(4); //{4}
    d.emplace_back(3); //{4,3}
    d.push_front(2); //{2,4,3}
    d.emplace_front(1); //{1,2,4,3}
    
    d.pop_back(); //{1,2,4}
    d.pop_front();//{2,4}
    
    cout<< d.back()<<endl; //4
    cout<< d.front(); //2

    //rest all functions are same as vectors
    //begin, end, rbegin, rend, clear, insert, swap, size

    return 0;

}
