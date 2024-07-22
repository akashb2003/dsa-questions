// You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

// Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

 

// Example 1:


// Input: root = [4,2,7,1,3], val = 5
// Output: [4,2,7,1,3,5]
// Explanation: Another accepted tree is:

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

    private:
    TreeNode* solve(TreeNode* node, int val)
    {
        if(node==NULL)
        {
            node=new TreeNode(val);
            return node;
        }
        
        if(val < node->val)
        {
            node->left=solve(node->left, val);
        }
        else if(val > node->val)
        {
            node->right=solve(node->right, val);
        }
        
        return node;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        return solve(root, val);
    }
};
