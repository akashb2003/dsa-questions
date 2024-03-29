// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length())
        {
            return false;
        }
        
        int ind[26]={0};
        
        for(int i=0;i<s.length();i++)
        {
            ind[s[i]-'a']++;
            ind[t[i]-'a']--;
        }
        
        for(int i=0;i<26;i++)
        {
            if(ind[i] !=0)
            {   
                return false;
            }
           
        }
        return true;
    }
};
