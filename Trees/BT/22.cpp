bool getPath(Tree *root, int x, vector<int> &arr){
  if(!root) return false;
  arr.push_back(root->val);
  if(root->val) return true;

  if(getPath(root->left,x ,arr) || getPath(root->right,x , arr){
    return true;
  arr.pop_back();
  return false;
}

public:
  vector<int> solve(TreeNode* A, int B){
    vector<int>arr;
    if(!A) return arr;
    getPath(A, B, arr);
    return arr;
}
