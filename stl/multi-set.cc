#include <bits/stdc++.h>

using namespace std;

int main()
{
    //everything is same as set but can only stores duplicats
    cout<<"Multi Sets\n\n";
    
    multiset<int> ms;
    
    ms.insert(1); //{1}
    ms.insert(1); //{1,1}
    ms.emplace(1); //{1,1,1}
    
    //begin(),end(), rbegin(),rend(), size(),
    //empty(), swap() - same functions
    
    cout<<ms.count(1); //3 
    
    ms.erase(1); //{} erases all 1s
    
    ms.insert(1); //{1}
    ms.insert(1); //{1,1}
    ms.emplace(1); //{1,1,1}
    ms.insert(1); //{1}
    
    //to earse only one 1
    ms.erase(ms.find(1));
    
    ms.erase(ms.find(1), ms.find(1) + 2); //error.. doubt
    
    return 0;
}
