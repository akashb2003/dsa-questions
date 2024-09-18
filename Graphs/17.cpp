// You are given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

// Examples :

// Input:
// n = 9, m = 10
// edges=[[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
// src=0
// Output:
// 0 1 2 1 2 3 3 4 4

// Input:
// n = 4, m = 2
// edges=[[1,3],[3,0]] 
// src=3
// Output:
// 1 1 -1 0

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>adj[N];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>dist(N,1e9);
        queue<int>q;
        q.push(src);
        dist[src]=0;
        
        while(!q.empty()){
            int u = q.front(); 
            q.pop();
            for(auto v:adj[u]){
                if(dist[u]+1<dist[v]){
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }
        }
        return dist;
    }
};
