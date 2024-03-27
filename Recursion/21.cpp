// Given a string s, partition s such that every 
// substring
//  of the partition is a 
// palindrome
// . Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> partitions;
        vector<string> path;
        backtrack(0, s, path, partitions);
        return partitions;
    }
    
private:
    bool isPalindrome(const string& sub) {
        int left = 0, right = sub.length() - 1;
        while (left < right) {
            if (sub[left++] != sub[right--]) {
                return false;
            }
        }
        return true;
    }
    
    void backtrack(int start, const string& s, vector<string>& path, vector<vector<string>>& partitions) {
        if (start == s.length()) {
            partitions.push_back(path);
            return;
        }
        
        for (int end = start + 1; end <= s.length(); ++end) {
            string sub = s.substr(start, end - start);
            if (isPalindrome(sub)) {
                path.push_back(sub);
                backtrack(end, s, path, partitions);
                path.pop_back();
            }
        }
    }
};
