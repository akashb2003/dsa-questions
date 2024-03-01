// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

class Solution {
public:
    int expandCenter(string &s, int l, int r){
        int yes=0;
        while(l>=0 && r<= s.length()){
            if(s[l]!=s[r]) break;
            l--; r++;
            yes++;
        }
        return yes;
    }

    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0; i< s.length(); i++){
            int oddLen = expandCenter(s, i,i);
            int evenLen = expandCenter(s, i,i+1);
            if(oddLen) ans+= oddLen;
            if(evenLen) ans+= evenLen;
        }
        return ans;
    }
};
