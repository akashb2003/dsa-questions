// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

 

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq; //min heap
        for(int ele:nums){
            pq.push(ele);
            if(pq.size()>k) pq.pop();
        }

        return pq.top();
    }
};
