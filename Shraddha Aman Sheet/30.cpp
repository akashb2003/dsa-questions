// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int i,j;
        char c;
        for(i = 0; i < strs[0].length(); i++){
            c = strs[0][i];
            for(j = 0; j < strs.size(); j++){
                if(strs[j][i] != c){
                    return ans;
                }
            }
            ans += c;
        }
        return ans;
    }
};
