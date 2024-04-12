// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.
 

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) 
            return false;
        string temp = s+s;
        if(temp.find(goal) == string::npos) 
            return false;
        return true;
    }
};
