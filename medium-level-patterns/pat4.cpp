/*

A
AB
ABC
ABCD

*/
#include <iostream>

using namespace std;


int main()
{
    int n=6;
    for(int i=0; i<n-1;i++)
    {
        char ch = 'A';
        for(int j =1; j<=i+1;j++)
        {
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;

    }

    return 0;
}
