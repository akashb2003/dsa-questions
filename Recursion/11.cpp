// Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer modulo 109 + 7.

// Example 1:

// Input:
// N = 3
// Output: 5
// Explanation:
// 5 strings are (000,
// 001, 010, 100, 101).

class Solution{
public:
        
#define mod 1000000007
    
// 	#define ll long long
	ll countStrings(int n) {
	    // code here
	   // if(n==0) return 0;
	    int zeroind = 1;
	    int oneind = 1;
	    int sum = zeroind + oneind;
	    
	    if(n==1) return sum;
	    int i=2;
	    while(i<=n){
	        oneind = zeroind;
	        zeroind = sum;
	        sum = (zeroind + oneind)%mod;
	        i++;
	    }
	    return sum%mod;
	}
};
