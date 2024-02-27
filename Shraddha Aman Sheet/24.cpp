// Given an array arr containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.

// Example 1:

// Input:
// N = 6, K = 3
// arr[] = {2, 7, 6, 1, 4, 5}
// Output: 
// 4
// Explanation:
// The subarray is {7, 6, 1, 4} with sum 18, which is divisible by 3.

class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	    int mx=0;
	    int sum=0;
	    unordered_map<int,int> mp;
	    for(int i=0; i<n;i++){
	        sum += arr[i];
	        int rem = sum%k;
	        
	        if(rem==0){
	            mx = max(mx, i+1);
	        }
	        if(rem<0){
	            rem+=k;
	        }
	        if(mp.find(rem)==mp.end()){
	            mp[rem] = i;
	        }
	        else{
	            int len = i-mp[rem];
	            mx = max(mx, len);
	        }
	    }
	    
        return mx;
	    
	}
};
