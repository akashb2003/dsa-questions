// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

 

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int  n= nums.size();
        if(n==1) return nums[0];

        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        int s=1, e = n-2 ,mid = s+(e-s)/2;
        int ans = 0;

        while(s<=e){
            if(nums[mid]!= nums[mid+1] && nums[mid]!= nums[mid-1]){
                ans = nums[mid];
                break;
            }
            else if(mid%2 ==0 && nums[mid]==nums[mid+1] || mid%2 ==1 && nums[mid] == nums[mid-1]){
               s = mid+1;
            }

            else{
                e = mid-1;
            }

            mid = s+(e-s)/2;
        }
        return ans;
    }
};
