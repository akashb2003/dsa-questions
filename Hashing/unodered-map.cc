#include <iostream>
#include <unordered_map>

using namespace std;

int main() {

    //same as set and unordered_set difference
    //operation takes place in O(1)
    //worst case O(n)
  
    unordered_multimap<int, string> unorderedMultiMap;

    unorderedMultiMap.insert(make_pair(1, "Apple"));
    unorderedMultiMap.insert(make_pair(2, "Banana"));
    unorderedMultiMap.insert(make_pair(1, "Orange"));
    unorderedMultiMap.insert(make_pair(3, "Grapes"));
    unorderedMultiMap.insert(make_pair(2, "Pear"));

    return 0;
}
