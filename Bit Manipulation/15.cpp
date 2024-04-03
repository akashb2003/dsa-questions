// Given an integer ‘N’, your task is to write a program that returns all the divisors of ‘N’ in ascending order.



// For example:
// 'N' = 5.
// The divisors of 5 are 1, 5.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1 :
// 10
// Sample Output 1 :
// 1 2 5 10

vector<int> printDivisors(int n) {

    // Write your code here

    vector<int> ans;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (i != n / i)
                ans.push_back(n / i);a
        }
    }

    sort(ans.begin(), ans.end());

    return ans;

}
