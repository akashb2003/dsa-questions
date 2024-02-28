// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for(int i = 0; i < s.length(); i++) {
            if(isalnum(s[i])) {
                s1 += tolower(s[i]);
            }
        }
        
        int n = s1.length();
        for(int i = 0; i < n/2; i++) {
            if(s1[i] != s1[n-i-1]) {
                return false;
            }
        }
        
        return true;
    }
};
