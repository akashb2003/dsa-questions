// Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
// Note: Here Size equals the number of nodes in the subtree.

class NodeVal {
public:
    int min, max, size;
    NodeVal(int min, int max, int size) {
        this->min = min;
        this->max = max;
        this->size = size;
    }
};

class Solution {
public:
    NodeVal help(Node* root, int &maxSize) {
        if (!root) return NodeVal(INT_MAX, INT_MIN, 0);
        
        auto left = help(root->left, maxSize);
        auto right = help(root->right, maxSize);
        
        if (root->data > left.max && root->data < right.min) {
            int currentSize = left.size + right.size + 1;
            maxSize = std::max(maxSize, currentSize);
            return NodeVal(std::min(root->data, left.min), std::max(root->data, right.max), currentSize);
        }
        
        return NodeVal(INT_MIN, INT_MAX, 0); // This subtree is not a BST
    }

    int largestBst(Node *root) {
        int maxSize = 0;
        help(root, maxSize);
        return maxSize;
    }
};
