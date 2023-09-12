#include <bits/stdc++.h>

using namespace std;

int main()
{

    cout<<"queue\n\n";
    
    queue<int> q;
    q.push(4); //{4}
    q.emplace(3); //{4,3}
    q.push(2); //{4,3,2}
    q.emplace(1); //{4,3,2,1}
    
    q.back()+=5; // 1+5 = 6
    
    cout<<q.front()<<endl; //4
    cout<< q.back()<<endl; //6
    
    
    q.pop(); //{3,2,6}
    cout<<q.front()<<endl; //3
    
    //empty, swap, size same as stack

    return 0;

}
