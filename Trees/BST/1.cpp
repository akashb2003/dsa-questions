/*

Given a Binary Search Tree, modify the given BST such that it is balanced and has minimum possible height. Return the balanced BST.

Example1:

Input:
       30
      /
     20
    /
   10
Output:
     20
   /   \
 10     30
Example2:

Input:
         4
        /
       3
      /
     2
    /
   1
Output:
      3            3           2
    /  \         /  \        /  \
   1    4   OR  2    4  OR  1    3   
    \          /                  \ 
     2        1                    4

*/


class Solution{
    
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    
    void inorder(Node* root, vector<int> &v)
    {
        if(root==NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    Node* buildtree(vector<int> &v, int l, int r)
    {
        if(l>r) 
            return NULL;
        else
        {
            int mid = (l+r)/2;
            Node* head = new Node(v[mid]);
            head->left = buildtree(v,l,mid-1);
            head->right = buildtree(v,mid+1,r);
        }
    }
    
    Node* buildBalancedTree(Node* root)
    {
    	// Code here
    	vector<int> v;
    	inorder(root,v);
    	return buildtree(v, 0, v.size()-1);
    }
};
