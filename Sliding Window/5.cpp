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

class Solution {
public:

    int help(vector<int>&nums, int goal){
        int sum=0,cnt=0;
        int l=0,r=0;
        if(goal<0) return 0;
        while(r<nums.size()){
            sum+= nums[r];
            while(sum>goal){
                sum=sum- nums[l];
                l++;
            }
            cnt += r-l+1;
            r++;
        }

        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
      
        int ans1 = help(nums,goal);
        int ans2 = help(nums,goal-1);
        return ans1-ans2;
    }
};
