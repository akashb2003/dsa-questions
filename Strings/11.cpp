// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

// Return the sorted string. If there are multiple answers, return any of them.

 

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.

class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,int>> heap('z'+1,{0,0});
        for(char c:s){
            heap[c]={heap[c].first+1, c};
        }
        sort(heap.begin(),heap.end());
        string ans="";
        for(auto it: heap){
            ans = string(it.first,it.second)+ans;
        }
        return ans;
    }
};
