#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout<<"Vectors\n\n";
    
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    
    //emplace_back() is faster than push_back()
    v.emplace_back(12);
    
    //vector is similar to array we can print using index Ex: a[0],a[1]... or a.at(0),a.at(1)...
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    cout<<endl;
    
    //assgin 5 empty spaces
    vector<int> v1(5);
    
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1.at(i)<<endl;
    }
    cout<<endl;
    
    //assgin 5 spaces with value 100
    vector<int> v2(5,100);
    
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<endl;
    }
    cout<<endl;
    
    v2.emplace_back(60);
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<endl;
    }
    cout<<endl;
    
    //vector of pair
    vector<pair<int,int>>vp;
    vp.push_back({1,2});
    
    for(int i=0;i<vp.size();i++)
    {
        cout<<"Pair "<<i+1<<endl;
        cout<<vp[i].first<<endl;
        cout<<vp[i].second<<endl;
    }
    cout<<endl;
    
    //for emplace_back() need not to use ({..}) directly we can use () with 2 numbers in it 
    vp.emplace_back(3,4);
    for(int i=0;i<vp.size();i++)
    {
        cout<<"Pair "<<i+1<<endl;
        cout<<vp[i].first<<endl;
        cout<<vp[i].second<<endl;
    }
    cout<<endl;
    
    //printing using iterator
    //iterator points to the address, basically it stores the address
    vector<int> :: iterator it = v.begin();
    
    cout<<"address of it its pointing to: "<<&(*it)<<endl;
    cout<<"value of the address: "<<*(it)<<endl<<endl;
    
    it++;
    //after increment
    cout<<"address of it its pointing to: "<<&(*it)<<endl;
    cout<<"value of the address: "<<*(it)<<endl<<endl;
    
    // end() will points at next index of the last vector, hence we use it-- use point at last addree
    vector<int> :: iterator it1 = v.end();
    it1--;
    
    cout<<"address of it1 its pointing to: "<<&(*it1)<<endl;
    cout<<"value of the address: "<<*(it1)<<endl<<endl;
    
    //v.rend() means reverse end, points to the index after the last element
    vector<int> :: reverse_iterator it2 = v.rend();
    it2--;
    
    cout<<"address of it2 its pointing to: "<<&(*it2)<<endl;
    cout<<"value of the address: "<<*(it2)<<endl<<endl;
    
    //v.rbegin() means reverse begin, points to the last index
    vector<int> :: reverse_iterator it3 = v.rbegin();
   
    cout<<"address of it3 its pointing to: "<<&(*it3)<<endl;
    cout<<"value of the address: "<<*(it3)<<endl<<endl;
    
    // it3++ moves one index back not to the next position
    it3++;
    cout<<"address of it3 its pointing to: "<<&(*it3)<<endl;
    cout<<"value of the address: "<<*(it3)<<endl<<endl;
    
    //v.back() gives output of last index
    cout<<v.back()<<"\n\n";
    
    vector<int> v3;
    v3.emplace_back(12);
    v3.emplace_back(23);
    v3.emplace_back(34); 
    v3.emplace_back(45);
    v3.emplace_back(56);
    
    for(vector<int>:: iterator it = v3.begin(); it!=v3.end();it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<"\n\n";
    
    //using auto datatype, which will automatically assign the related datatype Ex: auto a = 10.33, here auto will check
    // the value 10.33 and assign datatype of 'a' to float. We can use these in for loop to reduce code
    
    for(auto it = v3.begin(); it!=v3.end();it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<"\n\n";
    
    //for each loop, in this 'it' is value itself so dont write *(it)
    for(auto it: v3)
    {
        cout<<it<<" ";
    }
    cout<<"\n\n";
    
    v3.erase(v3.begin()+1);//{12,34,45,56}
    
    v3.erase(v3.begin()+1,v3.begin()+3); //{12,56}
    
    v3.insert(v3.begin(),60); //{60,12,56}
    
    v3.insert(v3.begin()+1,4,10); //{60,10,10,10,10,12,56}
    
    vector<int> copy(2,50); //{50,50}
    v3.insert(v3.begin(),copy.begin(),copy.end()); //v3.insert(v3.begin()+1,4,10); //{60,10,10,10,10,12,56}
    
    v3.pop_back(); //{60,10,10,10,10,12}
    
    v3.swap(copy); //v3 and copy got swapped
    
    v3.clear(); //erase everything
    
    cout<<v3.empty(); //if empty then 1, else 0
    
    return 0;
}
