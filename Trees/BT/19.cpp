// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.

//                       20
//                     /    \
//                   8       22
//                 /   \        \
//               5      3       25
//                     /   \      
//                   10    14

// For the above tree, the bottom view is 5 10 3 14 25.
// If there are multiple bottom-most nodes for a horizontal distance from root, then print the later one in level traversal. For example, in the below diagram, 3 and 4 are both the bottommost nodes at horizontal distance 0, we need to print 4.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(!root) return ans;
        queue<pair<Node* ,int>>q;
        map<int,int>mp;
        q.push({root, 0});
        
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            int x = tmp.second;
            
            mp[x] = tmp.first->data;
            
            if(tmp.first->left) q.push({tmp.first->left,x-1});
            if(tmp.first->right) q.push({tmp.first->right,x+1});
        }
        
        for(auto p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
