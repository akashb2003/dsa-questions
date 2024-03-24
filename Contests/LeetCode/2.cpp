// Given a string s, return the maximum length of a 
// substring
//  such that it contains at most two occurrences of each character.
 

// Example 1:

// Input: s = "bcbbbcba"

// Output: 4

// Explanation:

// The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".

class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int>mp;
        int l=0, ans=0;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            while(mp[s[i]]>2){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans, 1+i-l);
        }
        return ans;
    }
};
