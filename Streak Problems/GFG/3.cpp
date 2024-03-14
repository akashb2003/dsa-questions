// Given a square matrix a of size n x n, where each cell can be either 'X' or 'O', you need to find the size of the largest square subgrid that is completely surrounded by 'X'. More formally you need to find the largest square within the grid where all its border cells are 'X'.

// Example 1:

// Input:
// n = 2
// a = [[X,X],
//      [X,X]]
// Output:
// 2
// Explanation:
// The largest square submatrix 
// surrounded by X is the whole 
// input matrix.
// Example 2:

// Input:
// n = 4
// a = [[X,X,X,O],
//      [X,O,X,X],
//      [X,X,X,O],
//      [X,O,X,X]]
// Output:
// 3
// Explanation:
// Here,the input represents following 
// matrix of size 4 x 4
// X X X O
// X O X X
// X X X O
// X O X X
// The square submatrix starting at 
// (0,0) and ending at (2,2) is the 
// largest submatrix surrounded by X.
// Therefore, size of that matrix would be 3.

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        vector<vector<int>> rig(n,vector<int>(n,0));
        vector<vector<int>> bot(n,vector<int>(n,0));
        
        for(int c=n-1;c>=0;c--){
            int cnt=0;
            for(int r=n-1;r>=0;r--){
                if(a[r][c]=='X'){
                    cnt++;
                }else{
                    cnt=0;
                }
                bot[r][c]=cnt;
            }
        }
        
        for(int r=0;r<n;r++){
            int cnt=0;
            for(int c=n-1;c>=0;c--){
                if(a[r][c]=='X'){
                    cnt++;
                }else{
                    cnt=0;
                }
                rig[r][c]=cnt;
            }
        }
        
        int ans=0;
        
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
             if(a[r][c]!='O'){
                int mini=min(bot[r][c],rig[r][c]); 
               while(mini>0){
                
                int a1=r+mini-1 ,a2=c;
                int b1=r ,b2=c+mini-1;
                int v1=rig[a1][a2],v2=bot[b1][b2];
                    if(min(v1,v2)>=mini){
                         ans=max(ans,mini);
                         break;
                    }else{
                        mini--;
                    }
               }
             }
            }
        }
        
        return ans;
    }
};
