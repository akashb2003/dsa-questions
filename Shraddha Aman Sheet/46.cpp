// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.

// Note: An island is either surrounded by water or boundary of grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

// Example 1:

// Input:
// grid = {{0,1},{1,0},{1,1},{1,0}}
// Output:
// 1
// Explanation:
// The grid is-
// 0 1
// 1 0
// 1 1
// 1 0
// All lands are connected.
// Example 2:

// Input:
// grid = {{0,1,1,1,0,0,0},{0,0,1,1,0,1,0}}
// Output:
// 2
// Expanation:
// The grid is-
// 0 1 1 1 0 0 0
// 0 0 1 1 0 1 0 
// There are two islands :- one is colored in blue 
// and other in orange.

class Solution {
  public:
    // Function to find the number of islands.
    bool help(int i,int j, int m, int n, vector<vector<char>> &grid){
        if(i<0 || j<0 || j==n || i==m || grid[i][j] == '0') return false;
        
        grid[i][j] = '0';
        
        help(i+1,j,m,n,grid);
        help(i-1,j,m,n,grid);
        help(i,j-1,m,n,grid);
        help(i,j+1,m,n,grid);
        help(i + 1, j + 1, m, n, grid); 
        help(i + 1, j - 1, m, n, grid); 
        help(i - 1, j + 1, m, n, grid); 
        help(i - 1, j - 1, m, n, grid);

        return true;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans =0;
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(help(i,j,m,n,grid)) ans++;
            }
        }
        return ans;
    }
};
