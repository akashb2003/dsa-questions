// Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

// NOTE: The adjacency list denotes the edges of the graph where edges[i] stores all other vertices to which ith vertex is connected.

// Examples:

// Input: V = 5, E = 5
// adj = [[1], [0, 2, 4], [1, 3], [2, 4], [1, 3]] 
// Output: 1
// Explanation: 

// 1->2->3->4->1 is a cycle.class Solution {
  public:
    
    bool bfs(int node, int vis[], vector<int> adj[]){
        vis[node]=1;
        queue<pair<int,int>>q;
        q.push({node,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(int it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(parent!=it){
                    return true;
                }
            }
        }
        return false;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfs(i,vis,adj))
                    return true;
            }
        }
        return false;
    }
};
