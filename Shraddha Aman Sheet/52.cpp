// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

// Example 1:
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int maxA = 0;
        int n = heights.size();

        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width=0;
                
                if(st.empty()) width = i;
                else width = i-st.top()-1;

                maxA = max(maxA, height*width);
            }
            st.push(i);
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxA = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>heights(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j] = 0;
            }
            int area = largestRectangleArea(heights);
            maxA = max(maxA, area);
        }

        return maxA;
    }
};
