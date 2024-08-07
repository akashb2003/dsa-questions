// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1,INT_MAX - 1));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for(int j=1;j<amount+1;j++){
            if(j%coins[0] == 0){
                dp[1][j] = j/coins[0];
            }
            else{
                dp[1][j] = INT_MAX-1;
            }
        }

        for(int i=2;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]<=j){
                    dp[i][j] = min(dp[i][j-coins[i-1]]+1, dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        int result = dp[n][amount];
        return result == INT_MAX - 1 ? -1 : result;
    }
};
