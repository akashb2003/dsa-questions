// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

#include <vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> lproduct(n);
        vector<int> rproduct(n);

        lproduct[0] = 1;
        for(int i = 1; i < n; i++) {
            lproduct[i] = lproduct[i - 1] * nums[i - 1];
        }

        rproduct[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            rproduct[i] = rproduct[i + 1] * nums[i + 1];
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            ans[i] = lproduct[i] * rproduct[i];
        }

        return ans;
    }
};
