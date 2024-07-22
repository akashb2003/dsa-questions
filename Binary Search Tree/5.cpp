// Given a BST and a number X, find Ceil of X.
// Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

// If Ceil could not be found, return -1.

// Example 1:

// Input:
//       5
//     /   \
//    1     7
//     \
//      2 
//       \
//        3
// X = 3
// Output: 3
// Explanation: We find 3 in BST, so ceil
// of 3 is 3.

int findCeil(struct Node* root, int input) {
    // your code here
    int ciel = -1;
    while(root){
        if(root->data == input){
            ciel = root->data;
            return ciel;
        }
        else if(root->data < input){
            root = root ->right;
        }
        else{
            ciel = root->data;
            root = root->left;
        }
    }
    return ciel;
}
