// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick+=dp[i-2];

            int nonpick = dp[i-1];
            dp[i] = max(pick,nonpick);
        }
        return dp[n-1];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1=nums[0], prev2=0;

        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick+=prev2;

            int nonpick = prev1;
            int curr = max(pick,nonpick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
