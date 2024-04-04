// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        int arr[256] = {0};
        int r=0, l=0;

        while(r<n){
            arr[s[r]]++;
            while(arr[s[r]]>1){
                arr[s[l]]--;
                l++;
            }
            maxLength = max(maxLength, r-l+1);
            r++;
        }
        return maxLength;
    }
};
