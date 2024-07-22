int minValue(struct Node *root) {
    // your code here
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}
