// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

// Example 1:


// Input: root = [1,2,2,3,4,4,3]
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

    bool isSame(TreeNode* left, TreeNode* right){
        if(left==NULL || right==NULL){
            return (left==right);
        }
        return
            (left->val== right->val)
            && isSame(left->left,right->right)
            && isSame(left->right,right->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isSame(root->left,root->right);
    }
};
