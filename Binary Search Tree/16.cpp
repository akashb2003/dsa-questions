// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

// Example 1:


// Input: root = [1,3,null,null,2]
// Output: [3,1,null,null,2]
// Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
  
//   

class Solution {
   
    TreeNode *Prev=nullptr, *First=nullptr , *Sec=nullptr;

    void Inorder(TreeNode* a)
    {
        if(!a) return ;
        Inorder(a->left);

        if(Prev && a->val<Prev->val){
            if(!First) First=Prev;
            Sec=a; 
        } 
      
        Prev=a;
        Inorder(a->right);
    }

public:
    void recoverTree(TreeNode* a) {
        Inorder(a);
        swap(First->val,Sec->val);
    }
};
