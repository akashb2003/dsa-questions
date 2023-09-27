// Given an array nums containing n distinct numbers in the range [0, n], return 
// the only number in the range that is missing from the array.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0, xor2=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            xor1 = xor1^nums[i];
            xor2 = xor2^i;
        }
        xor2 = xor2^n;
        
        return xor1^xor2;
    }
};
