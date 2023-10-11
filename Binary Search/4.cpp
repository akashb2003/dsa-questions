// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low = 0;
        int mid = low + (high-low)/2;
        int ans = 0;
        while(low<=high){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]< target){
                ans = mid+1;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            mid = low + (high-low)/2;
        }
        return ans;
    }
};
