class Solution {
  public:
    long long int topDown(int n) {
        // code here
        vector<long long int>dp(n+1, -1);
        return help1(dp, n);
    }
    long long int help1(vector<long long int> &dp, int n){
        if (n<=1) return n;
        if (dp[n]!=-1) return dp[n];
        return dp[n] = (help1(dp, n-1)+ help1(dp, n-2))% 1000000007;
    }
    long long int bottomUp(int n) {
        // code here
        if (n <= 0) return n;
        vector<long long int>dp(n+1, 0);
        dp[0]=0;
        dp[1] = 1;
        
        for(int i=2; i<n+1;i++){
            dp[i] = (dp[i-1]+dp[i-2])%1000000007;
        }
        return dp[n];
    }

    long long int spaceOptimized(int n) {
  
      int prev2 = 0;
      int prev = 1;
      
      for(int i=2; i<=n; i++){
          int cur_i = prev2+ prev;
          prev2 = prev;
          prev= cur_i;
      }
      cout<<prev;
      return 0;
    }

};
