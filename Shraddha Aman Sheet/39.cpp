// Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) present in the string str.
// Note: You have to return the answer module 109+7;
 

// Example 1:

// Input: 
// Str = "abcd"
// Output: 
// 4
// Explanation:
// palindromic subsequence are : "a" ,"b", "c" ,"d"
 

// Example 2:

// Input: 
// Str = "aab"
// Output: 
// 4
// Explanation:
// palindromic subsequence are :"a", "a", "b", "aa"

public:
    int mod = 1e9 +7;
    long long int dp[1001][1001];
    long long int rec(string &str, int i, int j){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        if(str[i]==str[j]) return dp[i][j] = (((rec(str,i,j-1))%mod + (rec(str, i+1, j))%mod)%mod + 1)%mod;
        
        else return dp[i][j] = ((rec(str,i,j-1))%mod + (rec(str, i+1, j))%mod - (rec(str,i+1, j-1))%mod + mod)%mod;
    }
    
    long long int  countPS(string str)
    {
       int n  = str.length();
       dp[n][n];
       memset(dp, -1, sizeof(dp));
       return (rec(str, 0 ,n-1))%mod;
    }

