// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

class Solution {
public:

     void solve(vector<int>& candidates, int target, int ind,vector<vector<int>> &ans, vector<int> &output){
        if(target==0){
            ans.push_back(output);
            return;
        }           
        if(target<0) return;
        for(int i=ind; i< candidates.size(); i++){
            if(i!=ind && candidates[i]==candidates[i-1])continue;
            output.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1,ans,output);
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(candidates.begin(),candidates.end());
        solve(candidates, target, 0,ans,output);
        return ans;
    }
};
