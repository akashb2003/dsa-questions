// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.

class Solution {
public:
    vector<int> singleNumber(vector<int>& arr) {
        long xorr=0;
        for(int i=0; i<arr.size(); i++){
            xorr = xorr ^ arr[i];
        }
        int bucket1 = 0, bucket2=0;
        long rightMostBit = (xorr&(xorr-1))^xorr;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]&rightMostBit) bucket1 = bucket1^arr[i];
            else bucket2 = bucket2^arr[i];
        }
        return {bucket1, bucket2};
    }
};
