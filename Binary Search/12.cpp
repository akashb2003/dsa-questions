// Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between
// 1 to N times which is unknown. Find how many times the array has been rotated. 

int pivote(vector<int> &arr){
    int s=0,e=arr.size()-1, m= s+(e-s)/2;

    while(s<e){
        if(arr[s]<=arr[e]) return s;
        if(arr[s]<=arr[m]){
            s = m+1;
        }
        else{
            e = m;
        }
        m= s+(e-s)/2;
    }
    return s;
}

int findKRotation(vector<int> &arr){
    // Write your code here.    
    return pivote(arr);
}
