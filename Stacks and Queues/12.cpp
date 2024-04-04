// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0, l=0;
        int cnt =0;
        vector<int> arr(26,0);
        int windowL = 0, ans =0;

        while(r< s.length()){
            arr[s[r]-'A']++;
            cnt = *max_element(arr.begin(), arr.end());
            windowL = r-l+1;
            if((windowL - cnt)<=k){
                ans = max(windowL, ans);
            }
            else{
                arr[s[l]-'A']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};
