// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

// You must not use any built-in exponent function or operator.

// For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

class Solution {
public:
    int mySqrt(int x) {
        int s =0, e = x, m = s+(e-s)/2;
        int ans;
        while(s<=e){
            if(m > sqrt(x)){
                e = m-1;
            }
            if(m<= sqrt(x)){
                ans = m;
                s = m+1;
            }
            m = s+(e-s)/2;
        }
        
        return ans;
    }
};
