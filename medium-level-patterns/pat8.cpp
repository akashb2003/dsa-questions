/*
   A
  ABA
 ABCBA
ABCDCBA

*/

#include <iostream>

using namespace std;


int main()
{
    int n=4;

    for(int i=0; i<n;i++)
    {

        for(int j =1; j<n-i;j++)
        {
            cout<<" ";
        }

        char ch = 'A';
        for(int j=0;j<=i;j++)
        {
            cout<<ch;
            ch++;
        }
        ch--;
        for(int j=0;j<i;j++)
        {
            ch--;
            cout<<ch;
        }


        for(int j =1; j<n-i;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}`
