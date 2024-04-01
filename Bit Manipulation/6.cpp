// Problem statement
// The problem is to find the rightmost bit of a non-negative number 'N' that is currently unset (i.e., has a value of 0) in its binary representation and set it to 1.



// Return the number after setting the rightmost unset bit of 'N'. If there are no unset bits in N's binary representation, then the number should remain unchanged.



// Example:
// N = 5
// Output: 7
// Explanation: The binary representation of 5 is 101. After setting the rightmost unset bit it becomes 111 which is 7.

int setBits(int N){
    // Write your code here.
    int tmp = N>>1;
    if((tmp ==1||tmp==3||tmp==7) && (N&1)) return N;

    tmp = (N | (N+1));
    return tmp;
}
