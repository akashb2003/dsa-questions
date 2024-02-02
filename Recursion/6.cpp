// You have been given an integer 'N'. Your task is to generate and return all binary strings of length 'N' such that there are no consecutive 1's in the string.
// A binary string is that string which contains only ‘0’ and ‘1’.
// For Example:
// Let ‘N'=3, hence the length of the binary string would be 3. 

// We can have the following binary strings with no consecutive 1s:
// 000 001 010 100 101 
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 4
// Sample Output 1:
// 0000 0001 0010 0100 0101 1000 1001 1010 

void solve(vector<string>&ans, string temp,int n){
    if(temp.size()-n <=2){
        return;
    }
    for(int i= temp.size()-1;i>=n+2;i--){
        string k = temp;
        k[i] = '1';
        ans.push_back(k);
        solve(ans, k,i);
    }
    return;

}

vector<string> generateString(int N) {
    // Write your code here.
    string k="";
    vector<string>ans;
    for(int i = 0; i<N; i++){
        k+= '0';
    }
    ans.push_back(k);
    for(int i = N-1; i>=0; i--){
        string temp = k;
        temp[i] = '1';
        ans.push_back(temp);
        solve(ans,temp, i);
    }
    return ans;
}
