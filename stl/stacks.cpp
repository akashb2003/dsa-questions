#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Stack\n\n";
    
    stack<int>s;
    s.push(4); //{4}
    s.push(3); //{4,3}
    s.push(2); //{4,3,2}
    s.push(1); //{4,3,2,1}
    
    s.pop(); //{4,3,2}
    
    cout<<s.top()<<endl;// 2
    
    cout<<s.size()<<endl;// 3
    
    cout<<s.empty()<<endl; //0 -> not an empty stack
    
    stack<int> s1,s2;
    
    s1.push(4); //{4}
    s1.push(3); //{4,3}
    
    while(!s1.empty())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    } cout<<endl;
    s2.push(2); //{4,3,2}
    s2.push(1); //{4,3,2,1}
    
    while(!s2.empty())
    {
        cout<<s2.top()<<" ";
        s2.pop();
    }
    
    s1.swap(s2);
    
    while(!s2.empty())
    {
        cout<<s2.top()<<" ";
        s2.pop();
    }
    cout<<"\n\n";

    return 0;

}
