// A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

// For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
// Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 

// Example 1:

// Input: n = 1
// Output: 5
// Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

const int mod = 1e9 + 7;
class Solution {
public:
    int Pow(long long m, long long n){
        if(n == 0)
          return 1;

        long long x = Pow(m, n/2) % mod;
        
        if(n & 1)
          return (m * x * x) % mod; 
        
        else
          return (x * x) % mod;

    }
    int countGoodNumbers(long long n) {
        
       int x = Pow(5, n/2) % mod;
       int y = Pow(4, n/2) % mod;

        return (n&1) ? (5ll * x * y) % mod : (1ll * x * y) % mod;
    }
};
