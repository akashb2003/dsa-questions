// Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. Each point in the grid has some cost associated with it.



// Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which minimizes the sum of the cost of all the numbers along the path. You need to tell the minimum sum of that path.



// Note:
// You can only move down or right at any point in time.

#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0) dp[i][j] = grid[i][j];
            else{
                int left = INT_MAX;
                int up = INT_MAX;
                if(j>0) left = grid[i][j] + dp[i][j-1];
                if(i>0) up = grid[i][j]+ dp[i-1][j];
                
                dp[i][j] = min(left,up);
            }
        }
    }
    return dp[m-1][n-1];
}
