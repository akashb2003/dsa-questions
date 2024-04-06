// You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

// Return the sum of all subarray ranges of nums.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: 4
// Explanation: The 6 subarrays of nums are the following:
// [1], range = largest - smallest = 1 - 1 = 0 
// [2], range = 2 - 2 = 0
// [3], range = 3 - 3 = 0
// [1,2], range = 2 - 1 = 1
// [2,3], range = 3 - 2 = 1
// [1,2,3], range = 3 - 1 = 2
// So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaximum(nums) - sumSubarrayMins(nums);
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<pair<int,int>>stL, stR;

        for(int i=0;i<n;i++){
            int cnt = 1;
            while(!stL.empty() && stL.top().first > arr[i]){
                cnt += stL.top().second;
                stL.pop();
            }
            stL.push({arr[i],cnt});
            left[i] = cnt;
        }

        for(int i=n-1;i>=0;i--){
            int cnt = 1;
            while(!stR.empty() && stR.top().first >= arr[i]){
                cnt += stR.top().second;
                stR.pop();
            }
            stR.push({arr[i],cnt});
            right[i] = cnt;
        }
        long long ans=0;
        for(int i=0; i<n;i++){
            ans = ans+ arr[i] * (long long) (left[i] * right[i]);
        }
        return ans;
    }

    long long sumSubarrayMaximum(vector<int>& arr) {
        int n = arr.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        stack<pair<int,int>>stL, stR;

        for(int i=0;i<n;i++){
            int cnt = 1;
            while(!stL.empty() && stL.top().first < arr[i]){
                cnt += stL.top().second;
                stL.pop();
            }
            stL.push({arr[i],cnt});
            left[i] = cnt;
        }

        for(int i=n-1;i>=0;i--){
            int cnt = 1;
            while(!stR.empty() && stR.top().first <= arr[i]){
                cnt += stR.top().second;
                stR.pop();
            }
            stR.push({arr[i],cnt});
            right[i] = cnt;
        }
        long long ans=0;
        for(int i=0; i<n;i++){
            ans = ans+ arr[i] * (long long) (left[i] * right[i]);
        }
        return ans;
    }

};
