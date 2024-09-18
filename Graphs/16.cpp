// Given a Directed Acyclic Graph of n vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length m, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

// Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

// Examples :

// Input: n = 4, m = 2, edge = [[0,1,2],[0,2,1]]
// Output: 0 2 1 -1
// Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.
// Input: n = 6, n = 7, edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
// Output: 0 2 3 6 1 5
// Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3. Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.

class Solution {
  public:
  
    void topo(int node, vector<int>&vis,stack<int>&st,
    vector<pair<int,int>>adj[]){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it.first])
                topo(it.first,vis,st,adj);
        }
        st.push(node);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int>dist(N,1e9);
        dist[0] =0;
        stack<int>st;
        vector<int>vis(N,0);
        
        for(int i=0;i<N;i++){
            if(!vis[i])
                topo(i,vis,st,adj);
        }
        
        while(!st.empty()){
            int u = st.top(); st.pop();
            for(auto it:adj[u]){
                int v = it.first;
                int w = it.second;
                if(dist[u]+w<dist[v]){
                    dist[v] = dist[u]+w;
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1e9)
                dist[i]=-1;
        }
        
        return dist;
    }
};
