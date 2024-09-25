// You are given an array/list of ‘N’ integers. You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array/list.

// Note:
// A subsequence of an array/list is obtained by deleting some number of elements (can be zero) from the array/list, leaving the remaining elements in their original order.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= T <= 500
// 1 <= N <= 1000
// 0 <= ARR[i] <= 10^5

// Where 'ARR[i]' denotes the 'i-th' element in the array/list.

// Time Limit: 1 sec.
// Sample Input 1:
// 2
// 3
// 1 2 4
// 4
// 2 1 4 9
// Sample Output 1:
// 5
// 11
// Explanation to Sample Output 1:
// In test case 1, the sum of 'ARR[0]' & 'ARR[2]' is 5 which is greater than 'ARR[1]' which is 2 so the answer is 5.

// In test case 2, the sum of 'ARR[0]' and 'ARR[2]' is 6, the sum of 'ARR[1]' and 'ARR[3]' is 10, and the sum of 'ARR[0]' and 'ARR[3]' is 11. So if we take the sum of 'ARR[0]' and 'ARR[3]', it will give the maximum sum of sequence in which no elements are adjacent in the given array/list.

#include <bits/stdc++.h>

int help(vector<int> &nums, int ind){
    if(ind <=1 ) return nums[ind];
    int pick = nums[ind]+ help(nums,ind-2);
    int nonpick = 0 + help(nums,ind-1);
    return max(pick,nonpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    return help(nums,nums.size()-1);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

int help(vector<int> &nums, int ind,vector<int>&dp){
    if(ind<0) return 0;
    if(dp[ind]!= -1) return dp[ind];

    int pick = nums[ind]+ help(nums,ind-2,dp);
    int nonpick = 0 + help(nums,ind-1,dp);
    return dp[ind] = max(pick,nonpick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int>dp(n,-1);
    return help(nums,n-1,dp);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int>dp(n,-1);
    dp[0] = nums[0];
    
    for(int ind = 1;ind<n;ind++){
        int pick = nums[ind] ;
        if(ind>1) pick+= dp[ind-2];
        int nonpick = 0 + dp[ind-1];
        dp[ind] = max(pick,nonpick);
    }
    return dp[n-1];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int p1 = nums[0], p2 = 0;
    
    for(int ind = 1;ind<n;ind++){
        int pick = nums[ind];
        if(ind>1) pick+= p2;
        int nonpick = 0 + p1;
        int curr = max(pick,nonpick);
        p2 = p1;
        p1 = curr;
    }
    return p1;
}
