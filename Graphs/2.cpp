// You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
// Note: Use the recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.


// Example 1:

// Input: V = 5 , adj = [[2,3,1] , [0], [0,4], [0], [2]]

// Output: 0 2 4 3 1
// Explanation: 
// 0 is connected to 2, 3, 1.
// 1 is connected to 0.
// 2 is connected to 0 and 4.
// 3 is connected to 0.
// 4 is connected to 2.
// so starting from 0, it will go to 2 then 4,
// and then 3 and 1.
// Thus dfs will be 0 2 4 3 1.

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int node,int vis[], vector<int>&ans, vector<int> adj[]){
        vis[node]=1;
        ans.push_back(node);
        for(int it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,ans,adj);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]= {0};
        vis[0]=1;
        vector<int>ans;
        int start=0;
        dfs(start,vis,ans,adj);
        return ans;
    }
};
