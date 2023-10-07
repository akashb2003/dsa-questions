// You are given an integer array nums of length n which represents a permutation of all the integers in the range [0, n - 1].

// The number of inversions is the number of the different pairs (i, j) where:

// 0 <= i < j < n
// nums[i] > nums[j]

int Merge(vector<int> &a ,int low, int mid, int high)
{
    vector<int> temp;
    
    int left = low;
    int right = mid+1;
    int cnt=0;
    
    while(left<=mid && right <= high){
        if(a[left]<=a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            cnt+= (mid - left+1);
            right++;
        }
    }
    
    while(left<=mid){
        temp.push_back(a[left]);
        left++;
    }
    
    while(right<=high){
        temp.push_back(a[right]);
        right++;
    }
    
    for(int i=low; i<= high; i++){
        a[i] = temp[i-low]; 
    }

    return cnt;
}

int MergeSort( vector<int> &a, int low, int high){
    int cnt =0;
    if(low>=high) return cnt;
    
    int mid = (low+high)/2;
    
    cnt += MergeSort(a,low, mid);
    cnt += MergeSort(a,mid+1, high);
    cnt += Merge(a,low, mid, high);

    return cnt;
}


int numberOfInversions(vector<int>&a, int n) {
    // Write your code here.
    return MergeSort(a, 0, n-1);

}
