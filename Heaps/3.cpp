// Given an array arr of size n, the task is to check if the given array can be a level order representation of a Max Heap.

// Example 1:

// Input:
// n = 6
// arr[] = {90, 15, 10, 7, 12, 2}
// Output: 
// 1
// Explanation: 
// The given array represents below tree
//        90
//      /    \
//    15      10
//   /  \     /
// 7    12  2
// The tree follows max-heap property as every
// node is greater than all of its descendants.

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for(int i=n/2-1;i>=0;i--){
            int li = 2*i+1;
            int ri = 2*i+2;
            
            if(arr[i]<arr[li] || arr[i]<arr[ri])
                return false;
        }
        return true;
    }
};
