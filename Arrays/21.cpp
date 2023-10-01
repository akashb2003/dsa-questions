// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mapp;
        mapp[0] = 1;

        int preSum = 0, cnt =0;

        for(int i=0;i< nums.size(); i++){
            preSum += nums[i];
            int remove = preSum - k;
            cnt+= mapp[remove];
            mapp[preSum]++;
        }

        return cnt;
    }
};

