// Given a string s, reverse the order of characters in each word within a 
// sentence while still preserving whitespace and initial word order.

class Solution {
public:
    string reverseWords(string s) {
        int start =0,n = s.length();

        for(int i=0;i< n; i++){
            if(s[i] ==' ' || i == n-1) {
                reverse(s.begin()+ start, s.begin()+i + (i==n-1? 1 : 0));
                start = i+1;
            }
        }
        return s;
    }
};
