// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

 

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

class Solution {
public:
  
  int help(vector<int>&nums, int goal){
        int sum=0,cnt=0;
        int l=0,r=0;
        if(goal<0) return 0;
        while(r<nums.size()){
            sum+= (nums[r]%2);
            while(sum>goal){
                sum=sum- (nums[l]%2);
                l++;
            }
            cnt += r-l+1;
            r++;
        }

        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int goal) {
        int ans1 = help(nums,goal);
        int ans2 = help(nums,goal-1);
        return ans1-ans2;
    }
};
