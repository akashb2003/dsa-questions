// Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.

 

// Example 1:


// Input: nums = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,4,2,7,5,3,8,6,9]
// Example 2:


// Input: nums = [[1,2,3,4,5],[6,7],[8],[9,10,11],[12,13,14,15,16]]
// Output: [1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16]

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int>ans;
        queue<pair<int,int>>q;
        q.push({0,0});

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [i,j] = q.front();
                q.pop();
                ans.push_back(nums[i][j]);

                if(j==0 && i+1 < nums.size()) q.push({i+1, j});
                
                if(j+1 < nums[i].size()) q.push({i,j+1});
            }
        }
        return ans;
    }
};
