// Problem statement
// Given a string 'S' of length 'N', return all the subsequences of the given string.



// A subsequence is a sequence that can be derived from the given sequence by deleting zero or more elements without changing the order of the remaining elements.



// Note :
// You may return the subsequences in any order but they will be printed in lexicographically ascending order.

// If a string from the returned array has a length of zero, it will be represented as 'Empty String' in the output.

// Sample Input 1:
// abc
// Sample Output 1:
// 'Empty String'
// a
// ab
// abc
// ac
// b
// bc
// c

void solve(string s,  vector<string> &ans, string &output,int ind ){
    if(ind== s.length()){
        ans.push_back(output);
        return;
    }
    //exclude
    solve(s,ans,output, ind+1);

    //include
    output.push_back(s[ind]);
    solve(s,ans,output, ind+1);

    output.pop_back();
}

vector<string> generateSubsequences(string s)
{
    // Write your code here.
    vector<string> ans;
    string output = "";
    solve(s,ans,output,0);
    return ans;
}
