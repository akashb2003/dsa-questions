// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


// Example 1:

// Input:

// Output: 1
// Explanation: 3 -> 3 is a cycle

//Space Comp = O(2N)
class Solution {
  public:
  
    bool detectDFS(vector<int> adj[], vector<int>&vis, vector<int>&path,int node){
        path[node]=1;
        vis[node]=1;
        
        for(int it:adj[node]){
            if(!vis[it]){
                if(detectDFS(adj,vis,path,it))
                    return true;
            }
            else if(path[it])
                return true;
        }
        
        path[node] = 0;
        return false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>path(V,0);
        
        for(int i=0;i<V;i++){
            if(detectDFS(adj,vis,path,i))
                return true;
        }
        return false;
    }
};

// Optimized Space Comp = O(N)

class Solution {
  public:
  
    bool detectDFS(vector<int> adj[], vector<int>&vis,int node){
        vis[node]=1;
        vis[node]=2; //path[node]=1;
        
        for(int it:adj[node]){
            if(!vis[it]){
                if(detectDFS(adj,vis,it))
                    return true;
            }
            else if(vis[it]==2)
                return true;
        }
        
        vis[node]=1; //path[node] = 0;
        return false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        // vector<int>path(V,0);
        
        for(int i=0;i<V;i++){
            if(detectDFS(adj,vis,i))
                return true;
        }
        return false;
    }
};
