// There are n stones and an array of heights and Geek is standing at stone 1 and can jump to one of the following: Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and cost will be [hi-hj] is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches Stone n.

// Examples :
// Input: n = 5, k = 3 heights = {10, 30, 40, 50, 20}
// Output: 30
// Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum

class Solution {
  public:
    int minimizeCost(vector<int>& arr, int n, int k) {
        // Code here
        vector<int>dp(n);
        dp[0]=0;
        
        for(int i=1; i<n; i++){
            int minEg = INT_MAX;
            for(int j=1;j<=k; j++){
                if(i-j<0) break;
                int cost = dp[i-j]+ abs(arr[i]-arr[i-j]);
                minEg = min(minEg, cost);
            }
            dp[i] = minEg;
        }
        return dp[n-1];
    }
};
