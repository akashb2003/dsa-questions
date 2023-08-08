/*

1
2 3
4 5 6
7 8 9 10
*/

#include <iostream>

using namespace std;


int main()
{
    int n=6;
    int start = 1;
    for(int i=0; i<n-1;i++)
    {
        for(int j =1; j<=i+1;j++)
        {
            cout<<start<<" ";
            start++;
        }
        cout<<endl;

    }

    return 0;
}
