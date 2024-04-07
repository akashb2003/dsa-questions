// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>lastSeen(3,-1);
        int cnt =0;
        for(int i=0;i<s.length();i++){
            lastSeen[s[i]-'a']=i;
            if(lastSeen[0]!=-1 && lastSeen[1]!=-1 && lastSeen[2]!=-1)
            cnt += 1+ min(lastSeen[0],min(lastSeen[1],lastSeen[2]));
        }
        return cnt;
    }
};

//or

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0,a=-1,b=-1,c=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a')a=i;
            if(s[i]=='b')b=i;
            if(s[i]=='c')c=i;

            if(a!=-1 && b!=-1 && c!=-1){
                ans+=(1+min(a,min(b,c)));
            }
        }
        return ans;
    }
};
