// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

// Examples :

// Input:  n = 5, k = 4, dict = {"baa","abcd","abca","cab","cad"}
// Output: 1
// Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
// Similarly we can find other orders.

class Solution {
  public:
  
    void dfs( stack<int>&st,vector<int>&vis,vector<vector<int>> &adj,int node ){
        vis[node] = 1;
        for(int it:adj[node]){
            if(!vis[it])
                dfs(st,vis,adj,it);
        }
        st.push(node);
    }
  
    vector<int>topology(vector<vector<int>> &adj,int V){
        stack<int>st;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
                dfs(st,vis,adj,i);
        }
        vector<int>ans(V);
        for(int i=0;i<V;i++){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
  
    string findOrder(string dict[], int n, int k) {
        // code here
        vector<vector<int>> adj(k);
        for(int i=0;i<n-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int minLen = min(s1.length(),s2.length());
            for(int j=0;j<minLen;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<int>topo = topology(adj,k);
        
        string ans="";
        for(int it:topo){
            ans+= char(it+'a');
        }
        return ans;
    }
};
