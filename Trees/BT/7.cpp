// You are given a ‘Binary Tree’.



// Return the level-order traversal of the Binary Tree.



// Example:
// Input: Consider the following Binary Tree:

// Output: 
// Following is the level-order traversal of the given Binary Tree: [1, 2, 3, 5, 6, 4]


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 1 2 3 5 4 6 7 -1 -1 -1 -1 -1 -1 -1 -1


// Sample Output 1:
// 1 2 3 5 4 6 7

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

vector<int> levelOrder(TreeNode<int> * root){
    // Write your code here.
    queue<TreeNode<int> *>q;
    q.push(root);
    vector<int>ans;
    while(!q.empty()){
        TreeNode<int>* temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return ans;
}
