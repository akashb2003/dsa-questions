// Problem statement
// For a given integer 'N', you have to return the number of set bits in the binary representation of the numbers from 1 to 'N'.



// In a binary number '1' is considered as a set bit and '0' as not set.



// Example:
// If 'N' is 4, then

// 1 has a binary representation of 1
// 2 has a binary representation of 10
// 3 has a binary representation of 11
// 4 has a binary representation of 100

// Hence number of set bits is 5.

int countSetBits(int N)
{
    if(N==0) return 0;
    
    int x = 0, cnt = 0;
    while((1<<x)<=N){
        x++;
    }
    x--;
    int ans = (x*(1<<(x-1))) + (N-(1<<x) +1) + countSetBits(N-(1<<x));
    return ans;
}
