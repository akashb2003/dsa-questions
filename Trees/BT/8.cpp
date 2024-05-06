// You are given a ‘Binary Tree’.



// Return the preorder traversal of the Binary Tree.



// Example:
// Input: Consider the following Binary Tree:

// Output: 
// Following is the preorder traversal of the given Binary Tree: [1, 2, 5, 3, 6, 4]

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
#include<bits/stdc++.h>

vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.
    vector<int>ans;
    stack<TreeNode<int> *> st;
    st.push(root);

    while(!st.empty()){
        TreeNode<int> * temp = st.top();
        st.pop();

        ans.push_back(temp->data);

        if(temp->right){
            st.push(temp->right);
        }
        if(temp->left){
            st.push(temp->left);
        }
    }
    
    return ans;
}
