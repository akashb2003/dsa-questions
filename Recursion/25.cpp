// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.size(); ++i) {
            for (auto word: wordDict) {
                int start = i + 1 - word.size();
                if (start >= 0 && dp[start] && s.substr(start, word.size()) == word) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};

//    or    //

class Solution {
public:

    int help(string s,vector<string>& dict,  unordered_map<string, int>&dp ){
        int sz = s.length();
        if(sz==0) return 1;
        if(dp[s]!=0) return dp[s];

        for(int i=0;i<=sz;i++){
            int f=0;
            string ss = s.substr(0,i);
            for(int j=0; j<dict.size();j++){
                if(ss.compare(dict[j])==0){
                    f=1;
                    break;
                }
            }
            if(f==1 and help(s.substr(i,sz-i),dict, dp)==1) return dp[s] = 1;
        }
        return dp[s] = -1;
    }

    bool wordBreak(string s, vector<string>& dict) {
        unordered_map<string,int>dp;
        int x = help(s,dict,dp);
        return x==1? true:false;
    }
};
