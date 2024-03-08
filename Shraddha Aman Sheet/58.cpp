// Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

// Example 1:

// Input:
// L = 6, N = 78
// arr[] = {5, 20, 3, 2, 5, 80}
// Output: 1
// Explanation: (2, 80) have difference of 78.

bool findPair(int arr[], int size, int n){

    unordered_map<int,int>mp;

    sort(arr, arr+size);
    
    for(int i=0;i<size; i++){
        mp[arr[i]]++;
        if(n==0 && mp[arr[i]]>1)
            return true;
    }
    
    if(n==0)
        return false;
    
    for(int i=0;i<size; i++){
        if(mp.find(arr[i]+n) != mp.end()){
            return true;
        }
    }
    return false;
}

// or

bool findPair(int arr[], int size, int n){
    
    sort(arr, arr+size);
    n = abs(n);
    int i=0,j=1;
    
    while(i<=j && j<size){
        int diff = arr[j]-arr[i];
        
        if(diff==n && i!=j) return true;
        else if(diff>n) i++;
        else j++;
    }
    
    return false;
}
