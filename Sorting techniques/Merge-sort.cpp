#include <iostream>
#include <vector>
using namespace std;


/* 
best case, avg and worst case - O(N log2(N))
*/

void Merge(vector<int> &a ,int low, int mid, int high)
{
    vector<int> temp;
    
    int left = low;
    int right = mid+1;
    
    while(left<=mid && right <= high){
        if(a[left]<=a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
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
}

void MergeSort( vector<int> &a, int low, int high){
    
    if(low>=high) return;
    
    int mid = (low+high)/2;
    
    MergeSort(a,low, mid);
    MergeSort(a,mid+1, high);
    Merge(a,low, mid, high);
}

int main()
{
    vector<int>a;
    a.push_back(234);
    a.push_back(24);
    a.push_back(34);
    a.push_back(4);
    a.push_back(2);
    a.push_back(3);
    a.push_back(675);
    int n= 7;
    
    MergeSort(a,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
    return 0;
}
