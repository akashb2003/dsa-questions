// A step array is an array of integers where each element has a difference of at most k with its neighbor. Given a key x, we need to find the index value of x if multiple elements exist, and return the first occurrence of the key.

// Example 1:

// Input : arr[ ] = {4, 5, 6, 7, 6}, K = 1 
//         and X = 6
// Output : 2
// Explanation:
// In an array arr 6 is present at index 2.
// So, return 2.

int search(int arr[], int n, int x, int k)
{
    int i = 0;
    
    while (i < n) {
        if (arr[i] == x)
            return i;
        
        i = i + max(1, abs(arr[i] - x) / k);
    }
    
    return -1;
}
