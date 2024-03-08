// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears strictly more than N/2 times in the array.
 

// Example 1:

// Input:
// N = 3 
// A[] = {1,2,3} 
// Output:
// -1
// Explanation:
// Since, each element in 
// {1,2,3} appears only once so there 
// is no majority element.

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        if(size==0)
            return -1;
        else if(size==1)
            return a[0];
            
        map<int, int> num;
        for(int i=0;i<size;i++)
        {
            num[a[i]]++;
        }
        
        for(auto it: num){
            if(it.second > size/2)
                return it.first;
        }
        
        return -1;
    }
};
