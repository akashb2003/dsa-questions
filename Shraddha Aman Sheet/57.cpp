// Given a sorted array and a value x, the ceiling of x is the smallest element in an array greater than or equal to x, and the floor is the greatest element smaller than or equal to x. Assume that the array is sorted in non-decreasing order. Write efficient functions to find the floor and ceiling of x. 
// Examples : 

// For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
// For x = 0:    floor doesn't exist in array,  ceil  = 1
// For x = 1:    floor  = 1,  ceil  = 1
// For x = 5:    floor  = 2,  ceil  = 8int ceilSearch(int arr[], int low, int high, int x)
{
 
    // base condition if length of arr == 0 then return -1
    if (sizeof(arr) / sizeof(arr[0]) == 0) {
        return -1;
    }
    int mid;
  
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

///         or          ///

int main()
{
    vector<int> arr = { 1, 2, 8, 10, 10, 12, 19 };
    int n = arr.size();
    int x = 8;
    auto itr = lower_bound(arr.begin(), arr.end(),x); // returns iterator
    int idx = itr - arr.begin(); // converting to index;
    if (idx == n) {
        cout << "Ceil Element does not exist " << endl;
    }
    else {
        cout << "Ceil Element of " << x << " is " << arr[idx] << endl;
    }
    return 0;
}
