// Given a string S. For each index i(1<=i<=N-1), erase it if s[i] is equal to s[i-1] in the string.

// Example 1:

// Input:
// S = aabb
// Output:  ab 
// Explanation: 'a' at 2nd position is
// appearing 2nd time consecutively.
// Similiar explanation for b at
// 4th position.


{
 int n = s.length();
        if(n==0 || n==1) return s;

        if(s[0]==s[1]){
            int index = 0;
            while(s[index]==s[0] && index<n) index++;
            return s[0]+ removeDuplicates(s.substr(index));
        }
        return s[0]+ removeDuplicates(s.substr(1));
}
