// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool greater=0, less=0;
        int n=nums.size();
        for(int i=0; i<n-1; i++){
            int d=nums[i+1]-nums[i];
            if (d>0) greater=1;
            else if (d<0) less=1;
            if (greater && less) return 0;
        }
        return 1;
    }
};
