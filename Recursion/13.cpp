// Problem statement
// You are given an array 'A' of size 'N' and an integer'K'’. You need to generate and return all subarrays of array ‘A’ whose sum = ‘K’.



// Note: In the output, you will see the 2D array lexicographically sorted.



// Example:
// Input: ‘N’ = 6 ‘K’ = 3
// ‘A’ = [1, 2, 3, 1, 1, 1]
// Output: 3
// Explanation: Subarrays whose sum = ‘3’ are:
// [1, 2], [3], and [1, 1, 1]
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 6 3
// 1 2 3 1 1 1
// Sample Output 1:
// 3

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    vector<vector<int>> ans;
    vector<int> ds;
    long long sum=0;
    int i=0;
    for(int j=0;j<a.size();j++)
    {
        sum+=a[j];
        ds.push_back(a[j]);
        while(sum > k) 
        {
            sum-=a[i];
            i++;
            ds.erase(ds.begin());
        }
        if(sum==k)
        {
           ans.push_back(ds);
        }
    }
    return ans;
}
