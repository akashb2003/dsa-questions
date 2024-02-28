// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else {
                if (st.empty()) return false;
                char t1 = st.top(); st.pop();
                if ((s[i] == ')' && t1 != '(') || (s[i] == '}' && t1 != '{') || (s[i] == ']' && t1 != '['))
                    return false;
            }
            
        }
        return st.empty(); // Return true if stack is empty
    }
};
