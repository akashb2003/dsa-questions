// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, sum = 0;
        unordered_map<int, int> prefixSum;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];

            // Check if the current sum equals k
            if (sum == k) {
                count++;
            }

            // Check if there is a subarray with sum = current_sum - k
            if (prefixSum.find(sum - k) != prefixSum.end()) {
                count += prefixSum[sum - k];
            }

            // Update the prefix sum count
            prefixSum[sum]++;
        }

        return count;
    }
};
