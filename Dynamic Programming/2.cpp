class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> t(n+1, vector<int>(W+1, -1));
       
       return solve(W, wt, val, n, t);
       
       
    }
    
    int solve(int W, int wt[], int val[], int n, vector<vector<int>> &t){
        if(n==0 || W==0) return 0;
        
        if(t[n][W] != -1) return t[n][W];
        
        if(W>= wt[n-1]) 
            return t[n][W] = max((val[n-1]+ solve(W-wt[n-1], wt, val, n-1, t)), solve(W, wt, val, n-1, t));
        
        else
            return  t[n][W] = solve(W, wt, val, n-1, t);
    }
};
