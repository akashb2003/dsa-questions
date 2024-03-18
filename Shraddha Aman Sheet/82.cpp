// Given an array of integers and a sum B, find all unique combinations in the array where the sum is equal to B. The same number may be chosen from the array any number of times to make B.

// Note:
//         1. All numbers will be positive integers.
//         2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//         3. The combinations themselves must be sorted in ascending order.


// Example 1:

// Input:
// N = 4
// arr[] = {7,2,6,5}
// B = 16
// Output:
// (2 2 2 2 2 2 2 2)
// (2 2 2 2 2 6)
// (2 2 2 5 5)
// (2 2 5 7)
// (2 2 6 6)
// (2 7 7)
// (5 5 6)

vector<vector<int>>v;
    
    void solve(vector<int>&arr,int target,int sum,int idx,vector<int>&temp,int n){
        if(sum==target){
            v.push_back(temp);
            return;
        }
        if(sum>target){
            return;
        }
        if(idx>=n){
            return;
        }
        sum+=arr[idx];
        temp.push_back(arr[idx]);
        solve(arr,target,sum,idx,temp,n);
        sum-=arr[idx];
        temp.pop_back();
        solve(arr,target,sum,idx+1,temp,n);
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<int>temp;
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        int n=A.size();
        solve(A,B,0,0,temp,n);
        return v;
    }
