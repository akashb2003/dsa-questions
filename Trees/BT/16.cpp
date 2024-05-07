// You are given a binary tree having 'n' nodes.



// The boundary nodes of a binary tree include the nodes from the left and right boundaries and the leaf nodes, each node considered once.



// Figure out the boundary nodes of this binary tree in an Anti-Clockwise direction starting from the root node.



// Example :
// Input: Consider the binary tree A as shown in the figure:

// Output: [10, 5, 3, 7, 18, 25, 20]

// Explanation: As shown in the figure

// The nodes on the left boundary are [10, 5, 3]

// The nodes on the right boundary are [10, 20, 25]

// The leaf nodes are [3, 7, 18, 25].

bool isLeaf(TreeNode<int> *node){

    if(node->left==NULL&&node->right==NULL) return true;

    return false;

}

 

void left(TreeNode<int> *root,vector<int> &ans){

    TreeNode<int>* cur = root->left;

    while(cur){

        if(!isLeaf(cur)) ans.push_back(cur->data);

        if(cur->left) cur = cur->left;

        else cur = cur->right;

    }

}

 

void right(TreeNode<int> *root,vector<int> &ans){

    TreeNode<int>* cur = root->right;

    vector<int>temp;

    while(cur){

        if(!isLeaf(cur)) temp.push_back(cur->data);

        if(cur->right) cur = cur->right;

        else cur = cur->left;

    }

    for(int i=temp.size()-1;i>=0;i--){

        ans.push_back(temp[i]);

    }

}

 

void leaf(TreeNode<int> *root,vector<int> &ans){

    if(isLeaf(root)) ans.push_back(root->data);

    if(root->left) leaf(root->left,ans);

    if(root->right) leaf(root->right,ans);

}

 

vector<int> traverseBoundary(TreeNode<int> *root)

{

    // Write your code here.

    vector<int> ans;

    if(root==NULL) return ans;

    if(!isLeaf(root)) ans.push_back(root->data);

    left(root,ans);

    leaf(root,ans);

    right(root,ans);

    return ans;

}
