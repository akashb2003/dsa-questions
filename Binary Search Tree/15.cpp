// Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

 

// Example 1:


// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& elements) {
        if (root==NULL) return;
        inorder(root->left, elements);
        elements.push_back(root->val);
        inorder(root->right, elements);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> elements;
        inorder(root, elements);
        
        int left = 0;
        int right = elements.size() - 1;
        while(left < right) {
            int sum = elements[left] + elements[right];
            if(sum == k) return true;
            if(sum < k) left++;
            else right--;
        }
        return false;
    }
};
