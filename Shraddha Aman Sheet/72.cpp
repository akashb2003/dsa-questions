// Given 2 sorted arrays Ar1 and Ar2 of size N each. Merge the given arrays and find the sum of the two middle elements of the merged array.

 

// Example 1:

// Input:
// N = 5
// Ar1[] = {1, 2, 4, 6, 10}
// Ar2[] = {4, 5, 6, 9, 12}
// Output: 11
// Explanation: The merged array looks like
// {1,2,4,4,5,6,6,9,10,12}. Sum of middle
// elements is 11 (5 + 6).

class Solution {
public:
   int findMidSum(int ar1[], int ar2[], int n) {
    int merged[n * 2];
    int i = 0, j = 0, k = 0;
    
    // Merge the two sorted arrays into a single sorted array
    while (i < n && j < n) {
        if (ar1[i] < ar2[j]) {
            merged[k++] = ar1[i++];
        } else {
            merged[k++] = ar2[j++];
        }
    }
    
    while (i < n) {
        merged[k++] = ar1[i++];
    }
    
    while (j < n) {
        merged[k++] = ar2[j++];
    }
    
    // Calculate the indices of the two middle elements
    int mid1 = (n * 2) / 2 - 1;
    int mid2 = (n * 2) / 2;
    
    // Return the sum of the two middle elements
    return merged[mid1] + merged[mid2];
}

};
