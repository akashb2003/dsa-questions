// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[9],[3,15],[20],[7]]
// Explanation:
// Column -1: Only node 9 is in this column.
// Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
// Column 1: Only node 20 is in this column.
// Column 2: Only node 7 is in this column.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        
        int l=0,v=0;
        queue<pair<TreeNode*, pair<int,int>>>q;
        map<int, map<int, multiset<int>>>mp;

        q.push({root,{v,l}});
        
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            int x = tmp.second.first;
            int y = tmp.second.second;
            mp[x][y].insert(tmp.first->val);

            if(tmp.first->left){
                q.push({tmp.first->left,{x-1,y+1}});
            }
            if(tmp.first->right){
                q.push({tmp.first->right,{x+1,y+1}});
            }
        }

        for(auto p:mp){
            vector<int>temp;
            for(auto q:p.second){
                temp.insert(temp.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
