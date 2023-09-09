#include <bits/stdc++.h>

using namespace std;

int main()
{
    //list is faster than vector
    //with additon funciton to insert at front using push_front and emplace_front
    cout<<"Lists\n\n";
    
    list<int> l;
    l.push_back(4); //{4}
    l.emplace_back(3); //{4,3}
    l.push_front(2); //{2,4,3}
    l.emplace_front(1); //{1,2,4,3}
    
    for(auto p: l){
        cout<<p<<" ";
    }
    
    //{1,2,4,3}
    
    //rest all functions are same as vectors
    //begin, end, rbegin, rend, clear, insert, swap, size
    
    return 0;
}
