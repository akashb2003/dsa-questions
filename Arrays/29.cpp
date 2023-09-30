// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

// Return true if there is a 132 pattern in nums, otherwise, return false.

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN, n = nums.size();
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            if(third>nums[i]) return true;
            while(!st.empty() && st.top()< nums[i]){
                third = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};
