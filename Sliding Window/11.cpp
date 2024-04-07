// Given two strings s and t of lengths m and n respectively, return the minimum window 
// substring
//  of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> map(128, 0);
        int l=0, r=0, minlen=INT_MAX, ind=-1, cnt=0;

        for(auto it: t){
            map[it]++;
        }

        while(r<s.length()){
            if( map[s[r]] > 0 ){
                cnt++;
            }
            map[s[r]]--;

            while(cnt == t.length()){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    ind = l;
                }

                map[s[l]]++;                
                if( map[s[l]] > 0 ){
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return minlen == INT_MAX ? "" : s.substr(ind, minlen);
    }
};
