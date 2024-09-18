// There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
// Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.


// Example 1:

// Input: 
// N = 4, P = 3
// prerequisites = {{1,0},{2,1},{3,2}}
// Output:
// Yes
// Explanation:
// To do task 1 you should have completed
// task 0, and to do task 2 you should 
// have finished task 1, and to do task 3 you 
// should have finished task 2. So it is possible.

class Solution {
public:
	bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    
	    //create adj[] graph
	    vector<vector<int>>adj(V);
	    
	   // for(int i=0;i<V;i++){
	        for(auto it:prerequisites){
	            adj[it.first].push_back(it.second);
	        }
	   // }
	    
	    queue<int>q;
        vector<int>inDegree(V,0);
        // vector<int>topo;
        
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
        
        int cnt=0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++; // topo.push_back(node);
            
            for(int it:adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0)
                    q.push(it);
            }
        }
        
        if(cnt!=V) return false;
        return true;
	}
};
