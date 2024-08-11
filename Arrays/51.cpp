// According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

// Example 1:


// Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

class Solution {
public:

    bool isValid(int x,int y, vector<vector<int>>& board){
        return (x>=0 && y>=0 && x<board.size() && y<board[0].size());   
    }

    void gameOfLife(vector<vector<int>>& board) {
        int dx[8] = {0,1,1,1,0,-1,-1,-1};
        int dy[8] = {1,1,0,-1,-1,-1,0,1};

        for(int r=0;r< board.size();r++){
            for(int c=0;c<board[0].size();c++){
                int cnt_live=0;
                for(int i=0;i<8;i++){
                    int x = r+dx[i], y = c+dy[i];
                    if(isValid(x,y,board) && abs(board[x][y])==1)
                        cnt_live++;
                }
                if(board[r][c]==1 && (cnt_live<2 || cnt_live>3))
                    board[r][c]= -1;
                if(board[r][c]==0 && cnt_live==3 )
                    board[r][c]= 2;
            }
        }
        for(int r=0;r< board.size();r++){
            for(int c=0;c<board[0].size();c++){
                if(board[r][c]==2)
                    board[r][c] = 1;
                else if (board[r][c] == -1)
                    board[r][c] = 0;
            }
        }
    }
};
