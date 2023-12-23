// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

// Example 1:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix[0].size(), n = matrix.size();
        int l=0, h = (m*n-1);

        while(l<=h){
            int mid = l+(h-l)/2;
            int row = mid/m;
            int col = mid % m;

            if(matrix[row][col]==target) return true;
            
            else if(matrix[row][col]<target){
                l = mid+1;
            }
            else h = mid -1;
        } 

        return false;
    }
};
