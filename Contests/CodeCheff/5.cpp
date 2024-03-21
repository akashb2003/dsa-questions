#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin>>t;
    while(t--){
    long long n;
    cin>>n;
    long long arr[n];
    unordered_map<long long, long long>mp;
    long long ans =0;
    
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=0; i<n; i++){
       if(arr[i]>1 && (3*arr[i])%(arr[i]-1)==0){
            ans+=mp[(3*arr[i])/(arr[i]-1)];
       }

       mp[arr[i]]++;
    }
    
    cout<<ans<<endl;
}
    return 0;
}
