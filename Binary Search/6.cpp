// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        vector<int> v(2, -1);

        while (low <= high) {
            int m = low + (high - low) / 2;
            
            if (nums[m] == target) {
                int left = m;
                int right = m;
                
                while (left >= 0 && nums[left] == target) {
                    left--;
                }
                while (right < n && nums[right] == target) {
                    right++;
                }
                
                v[0] = left + 1;
                v[1] = right - 1;
                return v;
            } else if (nums[m] < target) {
                low = m + 1;
            } else {
                high = m - 1;
            }
        }

        return v;
    }
};array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

