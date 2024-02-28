// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        vector<int> charIndex(128, -1); // Vector to store the index of the last occurrence of each character
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1; // Update the left pointer to the index immediately after the last occurrence of s[right]
            }
            charIndex[s[right]] = right; // Update charIndex with the current index of s[right]
            maxLength = max(maxLength, right - left + 1); // Update maxLength with the maximum length
        }

        return maxLength;
    }
};
