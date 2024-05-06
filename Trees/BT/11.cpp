// Given a binary tree, determine if it is 
// height-balanced
// .
// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: true

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

    int help(TreeNode* root){
        if(root==NULL) return 0;

        int lh = help(root->left);
        if(lh==-1) return -1;

        int rh = help(root->right);
        if(rh==-1) return -1;

        if(abs(lh-rh)>1) return -1;

        return 1 + max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        return help(root) != -1;
    }
};
