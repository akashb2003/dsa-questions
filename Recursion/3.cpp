// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
// Example 1:
// Input: x = 2.00000, n = 10
// Output: 1024.00000

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0 || x==1) return 1;
        if(n==1) return x;
        if(n==-1) return 1/x;

        double half = myPow(x,n/2);
        double res = half*half;
        
        if(n%2 != 0){
            res = (n>0) ?res*x : res/x;
        }
        return res;
    }
};
