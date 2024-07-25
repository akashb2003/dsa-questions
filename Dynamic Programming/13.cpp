// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

class Solution {
public:

    int f(vector<int>& tmp){
        int n = tmp.size();

        int prev1 = tmp[0], prev2 = 0;
        for(int i=1; i<n;i++){
            int pick = tmp[i]; 
            if(i>1) pick+=prev2;
            int nonpick = prev1;
            int curr = max(pick, nonpick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>temp1, temp2;

        for(int i=0; i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!= n-1) temp2.push_back(nums[i]);
        }

        return max(f(temp1), f(temp2));
    }
};
