// Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.

// NOTE*: A subarray is a contiguous part of any given array.

// Example 1:

// Input:
// N = 4, K = 2
// Arr = [100, 200, 300, 400]
// Output:
// 700
// Explanation:
// Arr3  + Arr4 =700,
// which is maximum.

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &arr , int N){
        // code here 
        long sum =0, maxi = 0;
        int i=0,j=0,size = arr.size();
        while(j<size){
            sum+= arr[j];
            if(j-i+1 < K) j++;
            else{
                maxi = max(maxi, sum);
                sum -= arr[i];
                i++; j++;
            }
        }
        return maxi;
    }
};
