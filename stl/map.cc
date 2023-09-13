#include <bits/stdc++.h>

using namespace std;

int main()
{
    //stores in a pair - KEY, VALUE. KEY is unique and VALUE can be duplicate
    // Both KEY and VALUE can any data type
    // Stores in accending order of KEY
    // operations happen in O(log n)
    cout<<"Map\n\n";
    
    map<int,int> mapp; //1 KEY, 1 VALUE
    
    map<int, pair<int,int>> mappp; //1 KEY, 2 VALUE
    
    map<pair<int,int>,int> mapppp; //2 KEY, 1 VALUE
    
    mapp[1] = 2;            //{ {1,2} }
    mapp.insert({3,1});     //{ {1,2}, {3,1} }
    mapp.emplace({2,4});    //{ {1,2}, {2,4} , {3,1} }
    
    for(auto it: mapp){
        cout<< it.first <<" "<< it.second<<endl;
    }
    
    cout<<mapp[1]; // 2
    cout<<mapp[5]; // NULL or 0
    
    auto it = mapp.find(3);
    cout<< *(it).second <<endl;
    
    auto it = mapp.find(10); //KEY not found, hence points to the index after the point, ie mapp.end()
    
    //Syntex:
    auto it = mapp.lower_bound(2);
    auto it = mapp.upper_bound(3);
    
    //erase, swap, size, empty are same
    
    return 0;
}
