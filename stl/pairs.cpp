#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout<<"Pairs\n\n";
    pair<int,int> p = {1,2};
    cout<<p.first<<" "<<p.second<<endl<<endl;
    
    pair<int, pair<int,int>> pp = {3,{4,5}};
    cout<<pp.first<<" "<<pp.second.first<<" "<<pp.second.second<<endl<<endl;
    
    pair<int,int> arr[] = {{6,7},{8,9},{10,11}};
    cout<< arr[0].first<<" "<<arr[0].second<<endl;
    cout<< arr[1].first<<" "<<arr[1].second<<endl;
    cout<< arr[2].first<<" "<<arr[2].second<<endl;

    return 0;
}

