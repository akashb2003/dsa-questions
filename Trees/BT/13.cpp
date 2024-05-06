// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.

 

// Example 1:


// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

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

    int help(TreeNode* root, int &maxi){
        if(root==NULL) return 0;
        int lh = max(0, help(root->left, maxi));
        int rh = max(0, help(root->right, maxi));
        maxi = max(maxi, lh + rh + root->val);
        return root->val + max(lh,rh);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        help(root, maxi);
        return maxi;
    }
};
