//Find unique element

#include <iostream>

using namespace std;

int main()
{
    int n=7;
    int a[n]={1,4,5,5,3,1,4};
    
    int ans=0;
    
    for(int i=0;i<n;i++){
        ans = a[i]^ans;
    }
    
    cout<<ans;

    return 0;
}
