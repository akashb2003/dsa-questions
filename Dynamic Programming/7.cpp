// You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

// Return the minimum possible absolute difference.

 

// Example 1:

// example-1
// Input: nums = [3,9,7,3]
// Output: 2
// Explanation: One optimal partition is: [3,9] and [7,3].
// The absolute difference between the sums of the arrays is abs((3 + 9) - (7 + 3)) = 2.
  
//   
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return subsetSum(nums, sum);
    }

    int subsetSum(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> t(n + 1, vector<int>(sum + 1, 0));

        // Base case initialization
        for (int i = 0; i <= n; i++) {
            t[i][0] = 1; // There's always a subset with sum 0 (empty subset)
        }

        // Fill the subset sum table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i - 1] <= j) {
                    t[i][j] = t[i - 1][j - nums[i - 1]] || t[i - 1][j];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        // Find the minimum difference
        int mini = INT_MAX;
        for (int j = 0; j <= sum / 2; j++) {
            if (t[n][j]) {
                mini = min(mini, sum - 2 * j);
            }
        }

        return mini;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 6, 11, 5};
    cout << sol.minimumDifference(nums) << endl; // Expected output: 1 (subsets: {1, 6, 5} and {11})
    return 0;
}
