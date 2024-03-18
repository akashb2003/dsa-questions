// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at 
// (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order 
// we get DDRDRR DRDDRR.

class Solution{
    public:
    
    bool isPossible(int newX, int newY, vector<vector<int>> &map,vector<vector<bool>>&vis, int n){
        if(newX >=0 && newX <n && newY>=0 && newY<n && vis[newX][newY] ==0 && map[newX][newY]==1)
            return true;
        else
            return false;
    }
    
    void solve(int x, int y, vector<vector<int>> &map, int n, vector<vector<bool>>&vis,vector<string>&ans, const string path){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        vis[x][y]=1;
        //D, L, R, u
        if(isPossible(x+1, y,map, vis,n)){
            solve(x+1, y, map, n,vis, ans, path+"D");
        }
        //L
        if(isPossible(x, y-1,map, vis,n)){
            solve(x, y-1, map, n,vis, ans, path+"L");
        }
        //R
        if(isPossible(x, y+1,map, vis,n)){
            solve(x, y+1, map, n,vis, ans, path+"R");
        }
        //U
        if(isPossible(x-1, y,map, vis,n)){
            solve(x-1, y, map, n,vis, ans, path+"U");
        }
        vis[x][y]= 0;
    }
    
    vector<string> findPath(vector<vector<int>> &map, int n) {
        // Your code goes here
        if(map[0][0]==0) return {};
        
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        vector<string>ans;
        string path = "";
        
        solve(0,0,map,n,vis,ans,path);
        return ans;
    }
};
