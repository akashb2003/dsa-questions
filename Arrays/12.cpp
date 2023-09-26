// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.


class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                cnt++;
            }
        }
        if(nums[nums.size()-1]>nums[0]){
            cnt++;
        }
        return cnt<=1;
    }
};
