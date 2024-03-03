// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

class Solution {
public:

    bool help(int i,int j, int m, int n, vector<vector<char>>& board, string &word, int k){
        if(word.size() == k) return true;
        if(i<0 || j<0 || j==n || i==m || board[i][j] != word[k]) return false;
        
        char temp = board[i][j];
        board[i][j] = '#';
        
        bool op1 = help(i+1,j,m,n,board,word,k+1);
        bool op2 = help(i-1,j,m,n,board,word,k+1);
        bool op3 = help(i,j-1,m,n,board,word,k+1);
        bool op4 = help(i,j+1,m,n,board,word,k+1);

        board[i][j] = temp;

        return op1 || op2 || op3 || op4;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(help(i,j,m,n,board,word,0))
                return true;
            }
        }
        return false;
    }
};
