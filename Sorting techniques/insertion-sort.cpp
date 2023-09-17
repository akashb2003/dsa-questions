#include <iostream>

using namespace std;


/* 
avg and worst case - O(n^2)
best case - O(n) for ordered numbers
*/

void insertionSort(int a[], int n){
    for(int i=0 ; i<n; i++){
        int j=i;
        
        while(j>0 && a[j-1]>a[j]){
            swap(a[j],a[j-1]);
            j--;
        }
    }
}

int main()
{
    int a[] = {234,5,1,7,3,76,32,87,11};
    int n= 9;
    
    insertionSort(a,n);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
    return 0;
}
