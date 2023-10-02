// Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.
// Examples: 

// Input : arr[] = {4, 2, 2, 6, 4}, m = 6
// Output : 4
// Explanation : The subarrays having XOR of 
//               their elements as 6 are {4, 2}, 
//               {4, 2, 2, 6, 4}, {2, 2, 6},
//                and {6}

#include<map>

int subarraysWithSumK(vector < int > a, int k) {
    // Write your code here
    int xr = 0;
    map<int,int> mapp;
    mapp[xr]++;
    int cnt=0;

    for(int i=0;i< a.size(); i++){
        xr = xr^ a[i];
        int x = xr ^ k;
        cnt += mapp[x];
        mapp[xr]++;
    }

    return cnt;   
}
