// Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.

// Example 1:

// Input:
// m = 3, n = 4
// array1[] = {1,5,9}
// array2[] = {2,3,6,7}
// Output: 5
// Explanation: The middle element for
// {1,2,3,5,6,7,9} is 5

class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // Your code goes here
    int m = nums1.size();
    int n = nums2.size();
    int totalLength = m + n;
    int i = 0, j = 0;
    vector<int> merged;

    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            merged.push_back(nums1[i]);
            i++;
        } else {
            merged.push_back(nums2[j]);
            j++;
        }
    }

    while (i < m) {
        merged.push_back(nums1[i]);
        i++;
    }

    while (j < n) {
        merged.push_back(nums2[j]);
        j++;
    }

    if (totalLength % 2 == 0) {
        int mid = totalLength / 2;
        return (merged[mid - 1] + merged[mid]) / 2.0;
    } else {
        return merged[totalLength / 2];
    }
    
    }
};
