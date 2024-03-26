// Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

class Solution {
public:

    void solve(vector<int>&nums,vector<vector<int>> &ans,vector<int>&temp,int ind){
        ans.push_back(temp);
        for(int i=ind; i<nums.size();i++){
            if(i != ind && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums,ans,temp,i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(nums,ans,temp,0);
        return ans;
    }
};
