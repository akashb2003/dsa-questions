// Problem statement
// You are given an integer 'N'.



// Return 'odd' if the given number 'N' is odd, else return 'even'.



// For Example:
// N=5

// Output: odd
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 9
// Sample Output 1:
// odd
// Sample Input 2:
// 6
// Sample Output 2:
// even
// Constraints:
// 1 <= N <= 10^4
// Time Limit: 1 sec

string oddEven(int N){
    // Write your code here.
    int temp = N&1;
    if (temp==1) return "odd";
    return "even";
}
