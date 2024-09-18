// Given an adjacency list for a Directed Acyclic Graph (DAG) where adj_list[i] contains a list of all vertices j such that there is a directed edge from vertex i to vertex j, with  V  vertices and E  edges, your task is to find any valid topological sorting of the graph.

// In a topological sort, for every directed edge u -> v,  u must come before v in the ordering.


// Example 1:

// Input:

// Output:
// 1
// Explanation:
// The output 1 denotes that the order is
// valid. So, if you have, implemented
// your function correctly, then output
// would be 1 for all test cases.
// One possible Topological order for the
// graph is 3, 2, 1, 0.

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
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
        
        return topo;
	}
};
