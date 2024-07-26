// Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

// Note: Consider 1-based indexing.

// Example 1:

// Input:
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by 
// cutting in two pieces of lengths 2 and 
// 6, i.e., 5+17=22.

class Solution{
  public:
    int cutRod(int price[], int N) {
        //code here
        vector<vector<int>>dp(N+1 , vector<int>(N+1,0));
        vector<int>len(N);
        
        for(int i=1;i<N;i++){
            len[i-1] = i;
        }
        for(int i=1;i<N+1; i++){
            for(int j=1;j<N+1; j++){
                if(len[i-1]<=j){
                    dp[i][j] = max(price[i-1]+dp[i][j-len[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][N];
    }
};

//////////////////// OR ////////////////////

class Solution{
  public:
    int cutRod(int price[], int N) {
        //code here
        vector<vector<int>>dp(N+1 , vector<int>(N+1,0));
        
        for(int i=1;i<N+1; i++){
            for(int j=1;j<N+1; j++){
                if(i<=j){
                    dp[i][j] = max(price[i-1]+dp[i][j-i], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[N][N];
    }
};
