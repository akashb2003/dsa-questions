// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

// Example 1:


// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]
// Example 2:

// Input: mat = [[1,2],[3,4]]
// Output: [1,2,3,4]

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
         map<int , vector<int>> mp;
         vector<int> result;
         for(int i = 0 ; i< m ; i++)
         {
           for(int j =0 ; j < n ; j++)
             {
                 mp[i+j].push_back(mat[i][j]);
             }

         }
    
        bool flip = true;

        for(auto &it : mp)
        {
            if(flip)
             {
                 reverse(it.second.begin(), it.second.end());
             }
             flip = !flip;
             for(auto &num : it.second)
             {
                 result.push_back(num);
             }
        }
        

        return result;

    }
};
