
/*
A B C D
A B C
A B
A

*/

#include <iostream>

using namespace std;


int main()
{
    int n=6;
    for(int i=0; i<n;i++)
    {
        char ch = 'A';
        for(int j =1; j<n-i;j++)
        {
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;

    }

    return 0;
}
