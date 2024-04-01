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
        int N = nums.size();
        int n = pow(2,N);
        vector<vector<int>>ans;
        for(int i=0; i<n; i++){
            vector<int>tmp;
            for(int j=0; j<N; j++){
                if(i&(1<<j)) tmp.push_back(nums[j]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
