// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()==k) return "0";

        string ans;
        vector<int>st;
        int n = num.length();
        for(int i=0; i<n;i++){
            while(k>0 && !st.empty() && st.back() > num[i]){
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }
        while(k-- > 0){
            st.pop_back();
        }

        for(auto c : st){
            if(c== '0' && ans.empty())
                continue;
            ans += c;
        }
        return ans.empty()? "0" : ans;
    }
};
