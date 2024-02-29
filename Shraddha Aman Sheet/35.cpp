// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>um;
        vector<vector<string>>ans;
        string temp;
        for(auto s : strs){
            temp=s;
            sort(temp.begin(),temp.end());
            um[temp].push_back(s);
        }   
        for(auto s : um){
            ans.push_back(s.second);
        }
        return ans;

    }
};

// or

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto s: strs){
            string HashString = "";
            int arr[26] = {0};
            for(auto ch: s) arr[ch-'a']++;
            for(int i=0; i<26; i++){
                HashString.push_back(arr[i]);
                HashString.push_back('#');
            }
            mp[HashString].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto [key, value]: mp){
            ans.push_back(value);
        }
        return ans;
    }
};
