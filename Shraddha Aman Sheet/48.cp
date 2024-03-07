// You are given a 2-D Matrix 'MAT' having 'N' rows and 'M' columns, respectively. Your task is to find all elements which are present in each row of the matrix.

// Note :
// 1. The output array can contain the elements in any particular order.

// 2. Even if a particular element appears more than once in each matrix row, it should still be present only once in the output array.

#include <bits/stdc++.h>

vector<int> findCommonElements(vector<vector<int>> &mat)

{
    vector<int> ans;
    unordered_map<int,int>mp;
    unordered_set<int> s;

    int m = mat.size();
    int n = mat[0].size();

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            s.insert(mat[i][j]);
        }
        for(auto x:s)
        {
            mp[x]++;
        }

        s.clear();
    }

    for(auto x:mp)
    {
        if(x.second==m)
        {
            ans.push_back(x.first);
        }
    }

    return ans;

}
