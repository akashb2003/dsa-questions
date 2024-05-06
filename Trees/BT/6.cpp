// Problem statement
// You have been given a Binary Tree of 'n' nodes, where the nodes have integer values. Your task is to return its postorder traversal.



// For Example:
// For the given tree below,
// Postorder traversal for the given tree will be [4, 5, 2, 3, 1]. Hence, the answer is [4, 5, 2, 3, 1].

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 1 2 3 4 -1 -1 5 6 7 -1 -1 -1 -1 -1 -1
// Sample Output 1:
// 6 7 4 2 5 3 1
// Explanation:

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void insertNode(TreeNode* root, vector<int> &ans){
    if(root==NULL) return;
    insertNode(root->left, ans);
    insertNode(root->right, ans);
    ans.push_back(root->data);
}

vector<int> postorderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    insertNode(root, ans);
    return ans;
}
