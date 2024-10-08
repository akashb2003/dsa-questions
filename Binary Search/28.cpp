// A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

// Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

// You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

// You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

 

// Example 1:



// Input: mat = [[1,4],[3,2]]
// Output: [0,1]
// Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
// Example 2:



// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
// Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
 


class Solution {
public:

    int findMax(vector<vector<int>>& mat, int i, int n){
        int maxi = -1, ind = -1;
        for(int j=0;j<n;j++){
            if(maxi<mat[j][i]){
                maxi = mat[j][i];
                ind = j;
            }
        }
        return i;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0,high = m-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int maxiInd = findMax(mat,mid,n);
            int left = mid-1>=0? mat[maxiInd][mid-1] : -1;
            int right = mid+1<m? mat[maxiInd][mid+1] : -1;

            if(left< mat[maxiInd][mid] && right< mat[maxiInd][mid]){
                return {maxiInd, mid};
            }
            else if(left > mat[maxiInd][mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return {-1,-1};
    }
};
