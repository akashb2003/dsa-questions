// Given a sentence in the form of a string in uppercase, convert it into its equivalent mobile numeric keypad sequence.
// Please note there might be spaces in between the words in a sentence and we can print spaces by pressing 0.

string printSequence(string S)
{
    string ans="";
    string arr[] = {"2","22","222","3","33","333","4","44","444","5","55","555",
                  "6","66","666","7","77","777","7777","8","88","888","9","99","999","9999"};
    
    for(int i=0; i< S.length(); i++){
        if(S[i]==' ') ans+='0';
        else{
            int ind = S[i]-'A';
            ans+= arr[ind];
        }
    }
    return ans;
}
