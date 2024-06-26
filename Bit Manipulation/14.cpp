// You are given an integer 'N'.



// You must return the unique prime factors of 'N' in increasing order.



// For Example:
// For ‘N’ = 10.

// Unique prime factors are 2 and 5.

// Hence we return {2, 5}.

vector<int> countPrimes(int n)
{
    // Write your code here.
    vector<int>ans;
    for(int i=2;i<=sqrt(n); i++){
        if(n%i==0){
            ans.push_back(i);
            while(n%i==0)
                n = n/i;
        }
    }
    if(n!=1) ans.push_back(n);
    return ans;
}
