// Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

// Example 1:

// Input: 
// n = 5, m = 4
// mat = {{'X', 'X', 'X', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'O', 'O', 'X'}, 
//        {'X', 'O', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Output: 
// ans = {{'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'X', 'X'}, 
//        {'X', 'X', 'O', 'O'}}
// Explanation: 
// Following the rule the above matrix is the resultant matrix. 

class Solution{
public:
    
    void dfs(int r, int c, vector<vector<char>> &vis, vector<vector<char>> &mat, int delr[], int delc[], int n, int m){
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++){
            int nr = r + delr[i];
            int nc = c + delc[i];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && mat[nr][nc] == 'O'){
                dfs(nr, nc, vis, mat, delr, delc, n, m);
            }
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};
        vector<vector<char>> vis(n, vector<char>(m, 0));
         
        for(int j = 0; j < m; j++){
            if(!vis[0][j] && mat[0][j] == 'O')
                dfs(0, j, vis, mat, delr, delc, n, m);
            if(!vis[n-1][j] && mat[n-1][j] == 'O')
                dfs(n-1, j, vis, mat, delr, delc, n, m);
        }
        
        for(int i = 0; i < n; i++){
            if(!vis[i][0] && mat[i][0] == 'O')
                dfs(i, 0, vis, mat, delr, delc, n, m);
            if(!vis[i][m-1] && mat[i][m-1] == 'O')
                dfs(i, m-1, vis, mat, delr, delc, n, m);
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && mat[i][j] == 'O')
                    mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};
