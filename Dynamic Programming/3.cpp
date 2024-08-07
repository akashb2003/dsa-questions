class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> t(n+1, vector<int>(W+1, 0));
       
       for(int i=1; i<n+1; i++){
           for(int j=1; j<W+1; j++){
               
               if(wt[i-1]<= j)
                    t[i][j] = max((val[i-1]+t[i-1][j-wt[i-1]]), t[i-1][j]);
               else
                    t[i][j] = t[i-1][j];
           }
       }
       return t[n][W];
    }
};
