/*
Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
*/

class Solution {

public:

    int maxProduct(vector<int>& nums) {

        int n = nums.size();

        if (n==1) return nums[0];

        int prefix = 1;

       int sufix = 1;

        int maxi = INT_MIN;

        for(int i=0; i< n; i++){

           

           if( prefix == 0) prefix= 1;

           if( sufix == 0) sufix = 1;
           

            prefix *= nums[i];

            sufix *= nums[n-1-i];

maxi = max(maxi, max(prefix, suffix));
        }
        return maxi;
    }
};
