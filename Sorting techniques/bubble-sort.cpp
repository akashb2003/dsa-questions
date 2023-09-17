#include <iostream>

using namespace std;


/* O(n^2)

void bubbleSort(int a[], int n){
    for(int i=n-1; i>=0; i--){
        for(int j=0;j<=i-1;j++){
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }
    }
}

*/

// optimizing 
// If we give ordered numbers still it checks for every number O(n^2). To solve this we use a flag, if it never
// got swapped it will be understood as a ordered numbers and loop will break --> O(N)

void bubbleSort(int a[], int n){
    for(int i=n-1; i>=0; i--){
        
        int gotSwapped = 0;
        
        for(int j=0;j<=i-1;j++){
            if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
            gotSwapped = 0;
            }
        }
        
        if(gotSwapped = 0)
        break;
    }
}

int main()
{
    int a[] = {234,5,1,7,3,76,32,87,11};
    int n= 9;
    
    bubbleSort(a,n);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
    return 0;
}
