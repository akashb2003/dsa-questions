// There is an array of heights corresponding to 'n' stones. You have to reach from stone 1 to stone ‘n’.

// From stone 'i', it is possible to reach stones 'i'+1, ‘i’+2… ‘i’+'k' , and the cost incurred will be | Height[i]-Height[j] |, where 'j' is the landing stone.

// Return the minimum possible total cost incurred in reaching the stone ‘n’.

// Example:
// For 'n' = 3 , 'k' = 1, height = {2, 5, 2}.

// Answer is 6.


int help(int ind, int K, vector<int> &arr) {
    if (ind == 0) return 0;
    int mini = INT_MAX;

    for (int k = 1; k <= K; k++) {
        if (ind - k >= 0) { 
            int cost = help(ind - k, K, arr) + abs(arr[ind] - arr[ind - k]);
            mini = min(mini, cost);
        }
    }
    return mini;
}

int minimizeCost(int n, int K, vector<int> &arr) {
    return help(n - 1, K, arr); 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int help(int ind, int K, vector<int> &arr,vector<int>&dp) {
    if (ind == 0) return 0;
    if(dp[ind]!= -1) return dp[ind];
    
    int mini = INT_MAX;

    for (int k = 1; k <= K; k++) {
        if (ind - k >= 0) { 
            int cost = help(ind - k, K, arr,dp) + abs(arr[ind] - arr[ind - k]);
            mini = min(mini, cost);
        }
    }
    return dp[ind]=mini;
}

int minimizeCost(int n, int K, vector<int> &arr) {
    vector<int>dp(n+1,-1);
    return help(n - 1, K, arr,dp); 
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int minimizeCost(int n, int K, vector<int> &arr) {
    vector<int>dp(n,0);
    
    for(int ind=1;ind<n;ind++){
        int mini = INT_MAX;
        for (int k = 1; k <= K; k++) {
          if (ind - k >= 0) {
            int cost = dp[ind - k] + abs(arr[ind] - arr[inad - k]);
            mini = min(mini, cost);
          }
        }
        dp[ind] = mini;
    }
    return dp[n-1];
}
