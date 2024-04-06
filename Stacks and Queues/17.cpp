// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

// Example 1:

// Input: arr = [3,1,2,4]
// Output: 17
// Explanation: 
// Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
// Sum is 17.

//my code
#define mod 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
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
        int ans=0;
        for(int i=0; i<n;i++){
            ans = (ans+ (arr[i] * (long long) (left[i] * right[i]) % mod))%mod;
        }
        return ans;
    }
};

//beats 100%
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int len=arr.size(),sum=0;
        stack<int> M;
        
        for (int i=0;i<len;i++) {
            while (!M.empty() && arr[M.top()]>=arr[i]) {
                int x=M.top(),y=-1;
                M.pop();
                if (!M.empty()) y=M.top();

                //(arr[x])*(left side subarrays)*(right side subarrays)
                sum=(sum+arr[x]*((x-y)*(i-x)))%1000000007;
            }
            M.push(i);
        }

        int m1,m2=-1;
        while (!M.empty() || m2!=-1) {
            if (m2==-1) {
                m1=M.top(); M.pop();
            }
            else {
                m1=m2; m2=-1;
            }

            if (!M.empty()) {
                m2=M.top(); M.pop();
            }

            //(arr[x])*(left side subarrays)*(right side subarrays)
            int x=(unsigned)arr[m1]*(m1-m2)*(len-m1)%1000000007;
            sum=(sum+x)%1000000007;
        }

        return sum;
    }
};
