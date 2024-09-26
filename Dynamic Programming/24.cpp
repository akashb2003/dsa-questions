// You are Harshad Mehta’s friend. He told you the price of a particular stock for the next ‘n’ days.



// You are given an array ‘prices’ which such that ‘prices[i]’ denotes the price of the stock on the ith day.



// You don't want to do more than 2 transactions. Find the maximum profit that you can earn from these transactions.



// Note

// 1. Buying a stock and then selling it is called one transaction.

// 2. You are not allowed to do multiple transactions at the same time. This means you have to sell the stock before buying it again. 
// Example:
// Input: ‘n’ = 7, ‘prices’ = [3, 3, 5, 0, 3, 1, 4].

// Output: 6

// Explanation: 
// The maximum profit can be earned by:
// Transaction 1: Buying the stock on day 4 (price 0) and then selling it on day 5 (price 3). 
// Transaction 2: Buying the stock on day 6 (price 1) and then selling it on day 6 (price 4).
// Total profit earned will be (3 - 0) + ( 4 - 1) = 6. 
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 6
// 1 3 1 2 4 8
// Sample Output 1:
// 9
// Explanation Of Sample Input 1 :
// The maximum profit can be earned by:
// Transaction 1: Buying the stock on day 1 (price 1) and then selling it on day 2 (price 3). 
// Transaction 2: Buying the stock on day 3 (price 1) and then selling it on day 6 (price 8).
// Total profit earned will be (3 - 1) + ( 8 - 1) = 9.

#include <algorithm> 

int help(vector<int>& prices, int day, int buy, int n,vector<vector<vector<int>>>&dp,int cap) {
    if (day == n || cap==0) return 0;
    if(dp[day][buy][cap]!=-1) return dp[day][buy][cap];

    int pt = 0;
    if (buy) {

        pt = max(-prices[day] + help(prices, day + 1, 0, n,dp,cap), 
                      0 + help(prices, day + 1, 1, n,dp,cap));
    } else {
        pt = max(prices[day] + help(prices, day + 1, 1, n, dp,cap-1),
                 0 + help(prices, day + 1, 0, n, dp,cap));
    }
    return dp[day][buy][cap] = pt;
}

int maxProfit(vector<int>& prices){
    int n = prices.size();
    int day = 0, buy = 1;
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return help(prices, day, buy, n,dp,2);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));  // DP table: [days][buy/sell][cap]

    for (int day = n-1; day >= 0; day--) {  // Process days from the last one to the first
        for (int buy = 0; buy < 2; buy++) {
            for (int cap = 1; cap < 3; cap++) {
                int pt = 0;
                if (buy) {
                    // Buying case: Either buy the stock or skip
                    pt = max(-prices[day] + dp[day + 1][0][cap], 
                              0 + dp[day + 1][1][cap]);
                } else {
                    // Selling case: Either sell the stock or skip
                    pt = max(prices[day] + dp[day + 1][1][cap - 1],
                              0 + dp[day + 1][0][cap]);
                }
                dp[day][buy][cap] = pt;  // Store the result for this state
            }
        }
    }

    return dp[0][1][2];  // Max profit starting on day 0, with a 'buy' and 2 transactions allowed
}
