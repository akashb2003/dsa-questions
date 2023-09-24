// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2x.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int m=0;
        
        for(int i=0;i<32;i++){
            m= pow(2,i);
            if(m==n){
                return true;
            }
            if(m>n){
                return false;
            }
        }
 }
};
