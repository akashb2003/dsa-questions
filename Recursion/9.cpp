// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
class Solution {
public:

    void solve(string digits,vector<string> &ans,string output,int ind,string map[]){
        if(ind>= digits.length()){
            ans.push_back(output);
            return;
        }
        int num = digits[ind] - '0';
        string value = map[num];

        for(int i=0;i<value.length(); i++){
            output.push_back(value[i]);
            solve(digits,ans,output,ind+1,map);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output="";
        int ind = 0;
        solve(digits,ans,output,ind,map);
        return ans;
    }
};
