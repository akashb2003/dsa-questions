// Given an integer array nums of unique elements, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        solve(sub, ans, nums, 0);
        return ans;
    }
    void solve(vector<int> &sub,  vector<vector<int>> &ans, vector<int> &nums, int start){
        ans.push_back(sub);
        for(int i = start; i< nums.size(); i++){
            sub.push_back(nums[i]);
            solve(sub,ans,nums,i+1);
            sub.pop_back();
        }
    }
};
