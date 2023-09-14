#include <iostream>

using namespace std;

int main()
{
    int m;
    char c;
    cout<<"Enter string\n";
    string s;
    cin>>s;
    
    int hash[26] = {0};
    
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }
    
    cout<<"Enter num of test cases\n";
    
    cin>>m;
    cout<<"Enter test cases\n";
    for(int i=0;i<m;i++){
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }

    return 0;
}
