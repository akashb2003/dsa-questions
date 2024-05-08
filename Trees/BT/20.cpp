// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

// Example 1:


// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]

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
class Solution {
public:

    void insertNode(vector<int> &ans, TreeNode* root, int level){
        if(!root) return;
        if(level == ans.size()) ans.push_back(root->val);
        insertNode(ans, root->right, level+1);
        insertNode(ans, root->left, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        insertNode(ans,root,0);
        return ans;
    }
};
