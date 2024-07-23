// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2 != 0)
            return false;
        
        return subSetSum(nums, sum/2);
    }

    bool subSetSum(vector<int>& nums, int sum){
        int n = nums.size();
        vector<vector<int>> t(n+1,vector<int>(sum+1));

        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0) t[i][j] = 0;
                if(j==0) t[i][j] = 1;
            }
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){

                if(nums[i-1] <= j)
                    t[i][j] = (t[i-1][j-nums[i-1]] || t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
    }
};
