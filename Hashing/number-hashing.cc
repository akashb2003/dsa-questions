//we can declare int array of max size 10^6 inside int main() function, but globally we can declare 10^7
// similarlly bool array of max size is 10^7 inside int main() and globally we can delare till 10^8

#include <iostream>

using namespace std;

int main()
{
    int n, max,m,t=0;
    
    cout<<"Enter array size\n";
    cin>>n;
    
    int arr[n];
    
    cout<<"Enter array elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    cout<<"Enter maximum hash array number\n";
    cin>>max;
    
    int hash[max+1] = {0};
    
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }
    
    cout<<"Enter num of test cases\n";
    
    cin>>m;
    
    for(int i=0;i<m;i++){
        cin>>t;
        cout<<hash[t]<<endl;
    }
    

    return 0;
}
