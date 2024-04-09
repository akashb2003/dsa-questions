// You have been given ‘K’ different arrays/lists, which are sorted individually (in ascending order). 
// You need to merge all the given arrays/list such that the output array/list should be sorted in ascending order.

//   Sample Input 1:
// 1
// 2
// 3 
// 3 5 9 
// 4 
// 1 2 3 8   
// Sample Output 1:
// 1 2 3 3 5 8 9 

#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0;i<k;i++){
        int m = kArrays[i].size();
        for(int j=0;j<m;j++)
            pq.push(kArrays[i][j]);
    }
    vector<int>ans;
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
