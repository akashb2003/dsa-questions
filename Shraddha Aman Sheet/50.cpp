// Write a code which inputs two numbers m and n and creates a matrix of size m x n (m rows and n columns) in which every elements is either X or 0. The Xs and 0s must be filled alternatively, the matrix should have outermost rectangle of Xs, then a rectangle of 0s, then a rectangle of Xs, and so on.

// Examples:  

// Input: m = 3, n = 3
// Output: Following matrix 
// X X X
// X 0 X
// X X X

// Input: m = 4, n = 5
// Output: Following matrix
// X X X X X
// X 0 0 0 X
// X 0 0 0 X
// X X X X X


#include <bits/stdc++.h>
using namespace std;

void fill0X(int m, int n)
{
    int l=0,r=n-1,t=0,b=m-1;
    
    char arr[m][n];
    char ch = 'X';
    
    while(l<=r && t<=b){
        for(int j=l;j<=r;j++)
            arr[t][j] = ch;
        t++;
        
        for(int i=t;i<=b;i++)
            arr[i][r] = ch;
        r--;
        
        if(t<=b){
            for(int j=r;j>=l;j--)
                arr[b][j] = ch;
        }
        
        b--;
        
        if(l<=r){
            for(int i=b;i>=t;i--)
                arr[i][l] = ch;
        }
        
        l++;
        
        ch = (ch=='X'?'O':'X');
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;    
    }
    
    cout<<endl;
}

int main()
{
	puts("Output for m = 8, n = 8");
	fill0X(8, 8);
	
	puts("Output for m = 7, n = 10");
	fill0X(7, 10);
	
	return 0;
}

