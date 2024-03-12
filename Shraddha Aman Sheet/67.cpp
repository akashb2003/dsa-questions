// Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].

 

// Example 1:

// Input:
// n = 5
// nums[] = {10, 3, 5, 6, 2}
// Output:
// 180 600 360 300 900

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        if(n==0 || n==1) return {1};
        
        vector<long long int> prod(n,1);
        long long int temp = 1;
        for(int i=0;i<n;i++){
            prod[i] = temp;
            temp*= nums[i];
        }
        
        temp=1;
        for(int i=n-1; i>=0; i--){
            prod[i] *= temp;
            temp *= nums[i];
        }
        
        return prod;
    }
};
