// 1
// 01
// 101
// 0101
// 10101


#include <iostream>

using namespace std;


int main()
{
    int start = 0;
    int n=5;
    for(int i=1; i<=n;i++)
    {
        if(i%2!=0) start = 1;
        else start =0;
        
        for(int j=1;j<=i;j++)
        {
            cout<<start;
            start = 1-start;
        }
        cout<<endl;
        
        
        // if(i%2!=0)
        // {
        //     for(int j=1;j<=i;j++)
        //     {
        //         if(j%2!=0)
        //         {
        //             cout<<"1";
        //         }
        //         else
        //         {
        //             cout<<"0";
        //         }
        //     }
        // }
        
        // else
        // {
        //     for(int j=1;j<=i;j++)
        //     {
        //         if(j%2!=0)
        //         {
        //             cout<<"0";
        //         }
        //         else
        //         {
        //             cout<<"1";
        //         }
        //     }
        // }
       
        // cout<<endl;
        
    }

    return 0;
}
