// You are given two numbers 'L' and 'R'.



// Find the XOR of the elements in the range [L, R].



// For Example:
// For 'L' = 1 and ‘R’ = 5.
// The answer is 1.

int solve(int n){
    if(n%4==0) return n;
    else if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else return 0;
    
}

int findXOR(int L, int R){
    // Write your code here.
    return solve(L-1) ^ solve (R);
}
