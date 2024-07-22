// Given an array of integers arr[] representing inorder traversal of elements of a binary tree. Return true if the given inorder traversal can be of a valid Binary Search Tree.

// Note - In a valid Binary Search Tree all keys are unique.

// Examples :

// Input: arr[] = [8, 14, 45, 64, 100]
// Output: True
// Input: arr[] = [5, 6, 1, 8, 7]
// Output: False

class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        // your code here
         for(int i = 1; i<arr.size(); i++){

// we know that the inorder traversal of binary search tree comes in ascending order so we are checking whether the given input array elements are arranged in ascending order. If then return true else return false

          if(arr[i]>arr[i-1]){
              continue;
          }else{
              return false;
          }
      }
      return true;
    }
    
};
