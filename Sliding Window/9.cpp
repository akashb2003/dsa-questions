// You are given a string 'str' and an integer ‘K’. Your task is to find the length of the largest substring with at most ‘K’ distinct characters.

// For example:
// You are given ‘str’ = ‘abbbbbbc’ and ‘K’ = 2, then the substrings that can be formed are [‘abbbbbb’, ‘bbbbbbc’]. Hence the answer is 7.

#include<bits/stdc++.h>

int kDistinctChars(int k, string &str)
{
    // Write your code here
    int l=0,r=0,ans=0;
    unordered_map<int,int>mp;

    while(r<str.length()){
        mp[str[r]-'a']++;
       
        while(mp.size()>k){ //if(mp.size()>k) --> we can also use this, makes o(2n) -> o(n)
            mp[str[l]-'a']--;
            if(mp[str[l]-'a']==0) mp.erase(str[l]-'a');
            l++;
        }
        ans = max(ans,r-l+1);
        r++;
    }
    return ans;
}


