// Given the root of a binary tree, return all root-to-leaf paths in any order.

// A leaf is a node with no children.

 

// Example 1:


// Input: root = [1,2,3,null,5]
// Output: ["1->2->5","1->3"]

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// ///////////////////       OR         //////////////////

// class Solution {
// public:

//     void help(vector<string> &ans, string tmp, TreeNode* root){
//         if(!root) return;
//         tmp += to_string(root->val);

//         if(root->left == NULL && root->right == NULL){
//             ans.push_back(tmp);
//         }
//         tmp+= "->";

//         help(ans,tmp,root->left);
//         help(ans,tmp,root->right);
//     }

//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> ans;
//         if(!root) return ans;
//         string tmp = "";

//         help(ans,tmp,root);
//         return ans;
//     }
// };

// class Solution {
// public:
//     void solve(TreeNode* root,vector<string>&ans,string s)
//     {
//         if(root->left==NULL && root->right==NULL)
//         {
//             s+=to_string(root->val);
//             ans.push_back(s);
//             return;
//         }
//         s+=to_string(root->val);
//         s+="->";
//         if(root->left)
//         {
//             solve(root->left,ans,s);
//         }
//         if(root->right)
//         {
//             solve(root->right,ans,s);
//         }
//     }
//     vector<string> binaryTreePaths(TreeNode* root) 
//     {
//         string s="";
//         vector<string>ans;
//         solve(root,ans,s);
//         return ans;
//     }
// };
