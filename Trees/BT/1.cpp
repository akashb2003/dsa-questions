// Problem statement
// Given an array 'arr' that contains 7 integers representing the values of nodes in a binary tree. This represents level order. The first element of the array represents the value of the root node.



// Your objective is to construct a binary tree using the remaining 6 elements of the array, creating nodes for each of these values and return root node.



// For example:
// arr = [11, 22, 3, 54, 15, 23, 21]
// The 7 node binary tree is represented below.

#include <vector>

// class Node
// {
// public:
//     int data;
//     Node *left, *right;
//     Node()
//     {
//         this->data = 0;
//         left = NULL;
//         right = NULL;
//     }
//     Node(int data)
//     {
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
//     Node(int data, Node* left, Node* right)
//     {
//         this->data = data;
//         this->left = left;
//         this->right = right;
//     }
// };

Node* insertNodes(std::vector<int>& arr, int i, int n, Node* root){
    if(i < n){
        Node* temp = new Node(arr[i]);
        root = temp;

        root->left = insertNodes(arr, 2*i+1, n, root->left);
        root->right = insertNodes(arr, 2*i+2, n, root->right);
    }
    return root;
}

Node* createTree(std::vector<int>& arr){
    int n = arr.size();
    Node* root = nullptr;
    return insertNodes(arr, 0, n, root);
}
