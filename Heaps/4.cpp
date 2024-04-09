// You are given an array of size ‘N’ which is an array representation of min-heap.



// You need to convert this min-heap array representation to a max-heap array representation. Return the max-heap array representation.



// For Example
// Corresponding to given min heap : [1,2,3,6,7,8]

// It can be converted to the following max heap: [8,7,3,6,2,1]

void heapifyUp(vector<int>& arr, int ind, int n) {
    int l = 2 * ind + 1;
    int r = 2 * ind + 2;
    int largest = ind;
 
    if (l < n && arr[l] > arr[ind])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != ind) {
        swap(arr[ind], arr[largest]);
        heapifyUp(arr, largest, n);
    }
}
 
vector<int> MinToMaxHeap(int n, vector<int>& arr) {
    for (int i = (arr.size() - 2) / 2; i >= 0; i--) {
        heapifyUp(arr, i, n);
    }
    return arr;
}
