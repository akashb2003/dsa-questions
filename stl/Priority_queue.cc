#include <bits/stdc++.h>

using namespace std;

int main()
{

    cout<<"Priority queue\n\n";
    
    priority_queue<int> pq;
    
    //greater integers will be pushed at the top
    //similarly for char, float, long etc.
    //Called as Max heap
    
    pq.push(5); //{5}
    pq.push(1); //{5,1}
    pq.push(3); //{5,3,1}
    pq.push(2); //{5,3,2,1}
    pq.push(10); //{10,5,3,2,1}
    
    cout<<pq.top()<<endl; // 10
    pq.pop(); //pop greater element - 10
    
    //Min Heap
    priority_queue<int,vector<int>, greater<int>> pq2;
    
    pq2.push(5); //{5}
    pq2.push(1); //{1,5}
    pq2.push(3); //{1,3,5}
    pq2.push(2); //{1,2,3,5}
    pq2.push(10); //{2,2,3,5,10}
    
    cout<<pq2.top()<<endl; // 1
    pq2.pop(); //pop smallest element - 1
    
    return 0;

}
