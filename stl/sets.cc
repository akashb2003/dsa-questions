#include <bits/stdc++.h>

using namespace std;

int main()
{

    cout<<"Sets\n\n";
    
    set<int> s;
    
    //set stores unique elements, no multiples or duplicets
    //stores in incerasing order
    //every operation takes place in - O(log n) time
    
    s.insert(5); //{5}
    s.insert(4); //{4,5}
    s.emplace(5); //{4,5}
    s.insert(2); //{2,4,5}
    s.insert(3); //{2,3,4,5}
    
    //begin(),end(), rbegin(),rend(), size(),
    //empty(), swap() - same functions
    
    auto it = s.find(4); 
    //return the iterator pointing to 4
    cout<<&(*it)<<" "<<*it<<endl;
    
    auto it0 = s.find(100); 
    //if element not found then return the iterator pointing next to the last element
    
    s.erase(5); //{2,3,4}
    
    int count = s.count(2); //returns 1 because every element is unique else 0
    cout<<count<<endl;
    
    s.erase(it);// {2,3}
    
    s.insert(5); //{2,3,5}
    s.insert(4); //{2,3,4,5}
    
    auto it1 = s.find(3);
    auto it2 = s.find(5);
    
    s.erase(it1,it2); //{2,5} - 3 and 4 are erased, 5 is not included
    
    return 0;
}
