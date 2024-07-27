// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

// Example 1:

// Input : 
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output : 
// -8 0 -6 -6
// Explanation :
// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
                                                 
    vector<long long> ans;
    deque<long long>list;
    long long int j=0,i=0;
    while(j<N){
        if(A[j]<0) list.push_back(A[j]);
        if(j-i+1 == K){
            if(list.size()==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(list.front());
                if(list.front()==A[i]) list.pop_front();
            }
            i++;
        }
        j++;
    }
    return ans;
    
 }
