//count the number of digits in n

#include<bits/stdc++.h>

using namespace std;

int count_digits( int n )
{
   int x = n; int count =0;
   while( x !=0 ) 
   {
       x = x / 10;
       count++;
   }
   return count;
}

///////   OR   /////
/*

int count_digits( int n )
{
   int cnt = (int)(log10(n)+1);
   return count;
}

*/

int main()
{
   int n = 12345;
   cout<< "Number of digits in "<<n<<" is "<<count_digits(n);
   return 0;
}

