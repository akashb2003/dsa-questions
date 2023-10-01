// Given an m x n matrix, return all elements of the matrix in spiral order.
// Example 1:

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();

        int left = 0, right = m-1;
        int top = 0, bottom = n-1;

        vector<int> ans;
        while(top<=bottom && left<=right){
            for(int i = left; i<= right; i++){
                ans.emplace_back(a[top][i]);
            }

            top++;

            for(int i = top; i<= bottom; i++){
                ans.emplace_back(a[i][right]);
            }
            
            right--;
            
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    ans.emplace_back(a[bottom][i]);
                }
            }
            
            bottom--;

            if(left <= right){
                for(int i = bottom; i>= top; i--){
                    ans.emplace_back(a[i][left]);
                }
            }
            left++;
        }

        return ans;

    }
};
