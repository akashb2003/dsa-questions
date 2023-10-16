// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

// Example 1:

// Input: x = 4
// Output: 2
// Explanation: The square root of 4 is 2, so we return 2.

class Solution {
public:
    int mySqrt(int x) {
        int s = 0, e = x;
        int ans;
        while(s<=e){
            long long m = s+(e-s)/2;
            long long val = m*m;
            if(val <= (long long) (x)){
                s = m+1;
            }
            else{
                e = m-1;
            }
        }
        
        return e;
    }
};
