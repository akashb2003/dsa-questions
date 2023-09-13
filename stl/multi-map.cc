#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Everything same as map, only it can store multiple keys
    //only mapp[key] cannot be used here
    cout<<"Multi Map\n\n";

    multimap<int, string> multiMap;

    // Inserting key-value pairs into the multimap
    multiMap.insert(make_pair(1, "Apple"));
    multiMap.insert(make_pair(2, "Banana"));
    multiMap.insert(make_pair(1, "Orange"));
    multiMap.insert(make_pair(3, "Grapes"));
    multiMap.insert(make_pair(2, "Pear"));

    for (auto pair : multiMap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }

    /*
    output:
    Key: 1, Value: Apple
    Key: 1, Value: Orange
    Key: 2, Value: Banana
    Key: 2, Value: Pear
    Key: 3, Value: Grapes
    */
  
    return 0;
}
