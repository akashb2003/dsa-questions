// Given a string s, return the longest 
// palindromic
 
// substring
//  in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"

class Solution {
public:

    bool isPalindrome(string &s, int l, int r){
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        ans.push_back(s[0]);
        int maxlen = 1;
        for(int i=0; i<n-1;i++){
            for(int j=i+1; j<n; j++){
                if(isPalindrome(s,i,j)){
                    if(j-i+1 > maxlen){
                        maxlen = j-i+1;
                        ans = s.substr(i, j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};

// or // Efficient

class Solution {
public:

    string expandCenter(string &s, int l, int r){
        while(l>=0 && r<= s.length() && s[l]==s[r]){
        l--; r++;
        }
        return s.substr(l+1, r-l-1);
    }

    string longestPalindrome(string s) {
        string ans =s.substr(0,1);
        for(int i=0; i< s.length(); i++){
            string oddLen = expandCenter(s, i,i);
            string evenLen = expandCenter(s, i,i+1);
            if(oddLen.size() > ans.size()) ans = oddLen;
            if(evenLen.size() > ans.size()) ans = evenLen;
        }
        return ans;
    }
};
