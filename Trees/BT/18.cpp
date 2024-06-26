// Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

//        1
//     /     \
//    2       3
//   /  \    /   \
// 4    5  6   7

// Top view will be: 4 2 1 3 7
// Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the shadow of the tree and are at same position then consider the left ones only(i.e. leftmost). 
// For ex - 1 2 3 N 4 5 N 6 N 7 N 8 N 9 N N N N N will give 8 2 1 3 as answer. Here 8 and 9 are on the same position but 9 will get shadowed.

// Example 1:

// Input:
//       1
//    /    \
//   2      3
// Output: 2 1 3

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(!root) return ans;
        queue<pair<Node* ,int>>q;
        map<int,int>mp;
        q.push({root, 0});
        
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            int x = tmp.second;
            if(mp.find(x)==mp.end()) {
                mp[x] = tmp.first->data;
            }
            if(tmp.first->left) q.push({tmp.first->left,x-1});
            if(tmp.first->right) q.push({tmp.first->right,x+1});
        }
        
        for(auto p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }

};
