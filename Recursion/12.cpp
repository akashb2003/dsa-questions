// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]

class Solution {
public:

    void generate(vector<string>&ans,string &output,int o,int c){
        if(o==0 && c==0){
            ans.push_back(output);
            return;
        }
        if(o>0){
            output.push_back('(');
            generate(ans,output,o-1,c);
            output.pop_back();
        }
        if(c>0 && o<c){
            output.push_back(')');
            generate(ans,output,o,c-1);
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string output = "";
        vector<string>ans;
        generate(ans,output,n,n);
        return ans;
    }
};
