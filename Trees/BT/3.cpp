// You have been given a Binary Tree of 'N'

// nodes, where the nodes have integer values.



// Your task is to return the ln-Order, Pre-Order, and Post-Order traversals of the given binary tree.



// For example :
// For the given binary tree:

// The Inorder traversal will be [5, 3, 2, 1, 7, 4, 6].
// The Preorder traversal will be [1, 3, 5, 2, 4, 7, 6].
// The Postorder traversal will be [5, 2, 3, 7, 6, 4, 1].

void preOrder(TreeNode *root,vector<int>&v)
{
   if(root == NULL) return ;
   v.push_back(root->data);
   preOrder(root->left,v);
   preOrder(root->right,v);
}
void inOrder(TreeNode *root, vector<int>&v)
{
    if(root == NULL) return ;
    inOrder(root->left,v);
    v.push_back(root->data);
    inOrder(root->right,v);
}
void postOrder(TreeNode *root,vector<int>&v)
{
    if(root == NULL) return;
    postOrder(root->left,v);
    postOrder(root->right,v);
    v.push_back(root->data);   
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<int>pree;
    vector<int>ine;
    vector<int>poste;
    vector<vector<int>>v;
    preOrder(root,pree);
    inOrder(root,ine);
    postOrder(root,poste);
    
    
    v.push_back(ine);
    v.push_back(pree);
    v.push_back(poste);
    return v;
}

//            or           //


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



vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    if (root == NULL)
      return {};

    stack<pair<TreeNode*, int>>st;
    st.push({root, 1});
    vector<vector<int>> ans;
    vector<int>pre, post, ino;

    while(!st.empty()){
        auto node = st.top();
        st.pop();
        //pre
        if(node.second  == 1){
            pre.push_back(node.first->data);
            node.second = 2;
            st.push(node);
            if (node.first->left != NULL) {
                st.push({node.first->left, 1});
            }
        }
        //ino
        else if(node.second  == 2){
            ino.push_back(node.first->data);
            node.second = 3;
            st.push(node);
            if (node.first->right != NULL) {
                st.push({node.first->right, 1});
            }
        }
        else{
            post.push_back(node.first->data);
        }
    }
    ans.push_back(ino);    
    ans.push_back(pre);
    ans.push_back(post);

    return ans;
}
