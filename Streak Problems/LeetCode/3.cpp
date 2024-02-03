// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

// Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

 

// Example 1:

// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]
// Example 2:

// Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
// Output: 83

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int mx, ans, end, val;
        int n = arr.size();
        vector<int>dp(n + 1, 0);
        for(int i = n - 1; i >=0; i--){
            mx = 0, ans = 0;
            end=min(n, i + k);
            for(int j = i; j < end; j++){
                mx = max(mx, arr[j]);
                val = ((j - i + 1) * mx) + dp[j + 1];
                ans = max(val, ans);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};
