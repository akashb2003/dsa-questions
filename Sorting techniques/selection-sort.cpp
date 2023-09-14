#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n=8,arr[] = {5,1,4,64,89,12,13,0};
    for(int i=0; i<= n-2;i++){
        int mini = i;
        for(int j=i; j<=n-1;j++){
            if(arr[j]<arr[mini])
            swap(arr[mini],arr[j]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
