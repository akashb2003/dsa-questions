#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,num,m;
    cout<<"Enter array size\n";
    cin>>n;
    
    cout<<"Enter array\n";
    unordered_map<int,int>mpp;
  
    //we can also use map, which takes O(log n) in best, worst and average case
    //unordered_map takes O(1) for best and average case. Worst case O(n).
    //Hence use unordered_map, if there its taking more time use map
  
    for(int i=0;i<n;i++){
        cin>>num;
        mpp[num]++;
    }
    
    cout<<"Enter num of test cases\n";
    
    cin>>m;
    cout<<"Enter test cases\n";
    for(int i=0;i<m;i++){
        cin>>num;
        cout<<mpp[num]<<endl;
    }

    return 0;
}
