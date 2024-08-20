// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.

// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

 

// Example 1:

// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int>mp;
            for(int j=i;j<s.length();j++){
                mp[s[j]]++;
                int  maxi=0,mini=INT_MAX;
                for(auto it:mp){
                    maxi = max(maxi,it.second);
                    mini = min(mini,it.second);
                }
                ans+= maxi-mini;
            }
        }
        return ans;
    }
};
