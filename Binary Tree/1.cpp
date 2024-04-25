// Given an integer 'N', determine the maximum number of nodes present on 'Nth' level in a binary tree.



// For Example:

// N = 3
// For level 1, we have 1 node.
// For level 2, we have 2 nodes.
// For level 3, we have 4 nodes
// Output = 4, as level 3 has maximum 4 nodes.


int numberOfNodes(int N){
    return pow(2,N-1);
}
