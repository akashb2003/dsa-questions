// Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 


// Example 1:

// Input:
// N = 6
// arr[] = {3, 34, 4, 12, 5, 2}
// sum = 9
// Output: 1 
// Explanation: Here there exists a subset with
// sum = 9, 4+3+2 = 9.

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> t(n+1, vector<int> (sum+1));
        
        return solve(arr,sum,t, n);
    }
    
    bool solve(vector<int>&arr, int sum, vector<vector<int>> &t, int n){
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0)
                    t[i][j] = 0;
                if(j==0)
                    t[i][j] = 1;
            }
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(arr[i-1]<=j)
                    t[i][j] = (t[i-1][j-arr[i-1]] || t[i-1][j]);
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
    }
};
