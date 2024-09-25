//  Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.

// Example:
// Input:
// n = 4
// height = {10 20 30 10}
// Output:
// 20
// Explanation:
// Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost).
// Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost).
// so, total energy lost is 20 which is the minimum.


int help(int ind,vector<int> &arr){
    if(ind<=0) return 0;
    int left = help(ind-1,arr)+ abs(arr[ind]-arr[ind-1]);
    int right = ind>1? help(ind-2,arr)+ abs(arr[ind]-arr[ind-2]): INT_MAX;

    return min(left,right);
}

int frogJump(int n, vector<int> &arr)
{
    return help(n-1,arr);
}

//--------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h> 

int help(int ind,vector<int> &arr,vector<int>&dp){
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left = help(ind-1,arr,dp)+ abs(arr[ind]-arr[ind-1]);

    int right = INT_MAX;
    if(ind>1) right = help(ind-2,arr,dp)+ abs(arr[ind]-arr[ind-2]);

    return dp[ind] = min(left,right);
}

int frogJump(int n, vector<int> &arr)
{
    vector<int>dp(n+1,-1);
    return help(n-1,arr,dp);
}

//--------------------------------------------------------------------------------------------------------

int frogJump(int n, vector<int> &arr)
{
    vector<int>dp(n,0);
    for(int ind=1;ind<n;ind++){
        
        int left = dp[ind-1]+ abs(arr[ind]-arr[ind-1]);
        int right = INT_MAX;
        
        if(ind>1) right = dp[ind-2]+ abs(arr[ind]-arr[ind-2]);

        dp[ind] = min(left,right);
    }
    return dp[n-1];
}

//--------------------------------------------------------------------------------------------------------

int frogJump(int n, vector<int> &arr)
{
    
    int p1=0,p2=0;

    for(int ind=1;ind<n;ind++){
        
        int left = p1+ abs(arr[ind]-arr[ind-1]);
        int right = INT_MAX;
        
        if(ind>1) right = p2+ abs(arr[ind]-arr[ind-2]);

        int curr = min(left,right);

        p2 = p1;
        p1 = curr;
    }
    return p1;
}
