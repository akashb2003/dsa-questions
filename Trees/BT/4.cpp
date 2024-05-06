// Problem statement
// You are given a ‘Binary Tree’.



// Return the preorder traversal of the Binary Tree.



// Example:
// Input: Consider the following Binary Tree:

// Output: 
// Following is the preorder traversal of the given Binary Tree: [1, 2, 5, 3, 6, 4]


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 1 2 3 5 4 6 7 -1 -1 -1 -1 -1 -1 -1 -1


//  Sample Output 1:
// 1 2 5 4 3 6 7

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

// void insertNode(vector<int> &ans, TreeNode<int>* root) {
//     if (root == nullptr)
//         return;

//     ans.push_back(root->data);
//     insertNode(ans, root->left);
//     insertNode(ans, root->right);
// }

void insertNode(vector<int> &ans,TreeNode<int> * root){
    if(root == nullptr) return;
    
    ans.push_back(root->data);
    insertNode(ans,root->left);
    insertNode(ans,root->right);
}

vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.
    vector<int>ans;
    insertNode(ans,root);
    return ans;
}
