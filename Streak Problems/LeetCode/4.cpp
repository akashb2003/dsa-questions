// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4
// Explanation: The 4 subarrays are bolded and underlined below:
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// [1,0,1,0,1]
// Example 2:

// Input: nums = [0,0,0,0,0], goal = 0
// Output: 15

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        

        int preSum = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            //if (preSum == goal) res++;

            if (mp.find(preSum - goal) != mp.end()) {
                res += mp[preSum - goal];
            }
            mp[preSum]++;
        }

        return res;

    }
};
