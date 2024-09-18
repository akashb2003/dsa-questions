// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


// Example 1:

// Input:



// Output: 1
// Explanation: 3 -> 3 is a cycle

  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        queue<int>q;
        vector<int>inDegree(V,0);
        vector<int>topo;
        
        for(int i=0;i<V;i++){
            for(int it:adj[i]){
                inDegree[it]++;
            }
        }
        
        for(int i=0;i<V;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(int it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0)
                    q.push(it);
            }
        }
        
        if(topo.size()!=V) return true;
        return false;
        
    }
};
