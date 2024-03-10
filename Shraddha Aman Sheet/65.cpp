// Given an array of integers. Find the Inversion Count in the array. 

// Inversion Count: For an array, inversion count indicates how far (or close) the array is from being sorted. If the array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 

// Example 1:

// Input: N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 
// has three inversions (2, 1), (4, 1), (4, 3).
// Example 2:

// Input: N = 5
// arr[] = {2, 3, 4, 5, 6}
// Output: 0
// Explanation: As the sequence is already 
// sorted so there is no inversion count.

class Solution {
private:
    long long ans; // Declaring ans as a member variable
public:
    Solution() : ans(0) {} // Initializing ans in the constructor

    void merge(long long low, long long mid, long long high, long long arr[]) {
        vector<long long> temp;
        long long left = low, right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                // If arr[left] > arr[right], it forms inversion with all elements from left to mid
                ans += (mid - left + 1);
                temp.push_back(arr[right++]);
            }
        }

        // Copy remaining elements from left half
        while (left <= mid) temp.push_back(arr[left++]);

        // Copy remaining elements from right half
        while (right <= high) temp.push_back(arr[right++]);

        // Copy elements from temp back to original array
        for (long long i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    // Merge Sort function
    void mergeSort(long long low, long long high, long long arr[]) {
        if (low < high) {
            long long mid = (low + high) / 2;
            mergeSort(low, mid, arr);
            mergeSort(mid + 1, high, arr);
            merge(low, mid, high, arr);
        }
    }

    // Function to count inversions in the array
    long long int inversionCount(long long arr[], long long N) {
        ans = 0; // Resetting ans before each call to inversionCount
        long long start = 0, end = N - 1;
        mergeSort(start, end, arr);
        return ans;
    }
};
