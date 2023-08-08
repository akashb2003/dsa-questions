/*

1      1
12    21
123  321
12344321

*/

#include <iostream>

using namespace std;


int main()
{
    int start = 0;
    int n=5;
    for(int i=0; i<n-1;i++)
    {
        for(int j =1; j<=i+1;j++)
        {
            cout<<j;
        }
        for(int j=1; j<= n+1-(2*i);j++)
        {
            cout<<" ";
        }
        for(int j =i+1; j>=1;j--)
        {
            cout<<j;
        }

        cout<<endl;

    }

    return 0;
}
