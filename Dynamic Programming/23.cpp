// You have been given stock values/prices for N number of days. Every i-th day signifies the price of a stock on that day. Your task is to find the maximum profit which you can make by buying and selling the stocks.

//  Note :
// You may make as many transactions as you want but can not have more than one transaction at a time i.e, if you have the stock, you need to sell it first, and then only you can buy it again.

#include <algorithm> 

long help(long *values, int day, int buy, int n) {
    if (day == n) return 0;

    long pt = 0;
    if (buy) {
       
        pt = max(-values[day] + help(values, day + 1, 0, n), 
                      0 + help(values, day + 1, 1, n));
    } else {
        
        pt = max(values[day] + help(values, day + 1, 1, n), 
                      0 + help(values, day + 1, 0, n));
    }
    return pt;
}

long getMaximumProfit(long *values, int n) {
    int day = 0, buy = 1;
    return help(values, day, buy, n);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm> 

long help(long *values, int day, int buy, int n,vector<vector<long>>&dp) {
    if (day == n) return 0;
    if(dp[day][buy]!=-1) return dp[day][buy];

    long pt = 0;
    if (buy) {
       
        pt = max(-values[day] + help(values, day + 1, 0, n,dp), 
                      0 + help(values, day + 1, 1, n,dp));
        pt = max(values[day] + help(values, day + 1, 1, n,dp), 
                      0 + help(values, day + 1, 0, n,dp));
    }
    return dp[day][buy] = pt;
}

long getMaximumProfit(long *values, int n) {
    int day = 0, buy = 1;
    vector<vector<long>>dp(n,vector<long>(2,-1));
    return help(values, day, buy, n,dp);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <vector>

long getMaximumProfit(long *values, int n) {
    vector<vector<long>> dp(n+1,vector<long>(2, 0));

    // Base case: If we're at day n (beyond the last day), no profit can be made
    dp[n][0] = dp[n][1] = 0;

    // Fill the dp table
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy < 2; buy++) {
            long pt = 0;
            if (buy) {
                // Buying case: choose between buying or skipping
                pt = max(-values[ind] + dp[ind + 1][0], 
                              0 + dp[ind + 1][1]);
            } else {
                // Selling case: choose between selling or skipping
                pt = max(values[ind] + dp[ind + 1][1], 
                              0 + dp[ind + 1][0]);
            }
            dp[ind][buy] = pt;
        }
    }

    // Start from day 0 with the option to buy
    return dp[0][1];
}
