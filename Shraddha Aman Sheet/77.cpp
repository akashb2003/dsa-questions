// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

// The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.


// Example 1:

// Input:
// n = 5
// k = 3
// arr[] = {5,10,30,20,15}
// Output: 35
// Explanation: The most optimal way will be:
// Painter 1 allocation : {5,10}
// Painter 2 allocation : {30}
// Painter 3 allocation : {20,15}
// Job will be done when all painters finish
// i.e. at time = max(5+10, 30, 20+15) = 35

class Solution
{
     bool ispossiblesolution(int arr[],int n,int K,long long mid){
        long long timesum =0;
        int c=1;
        for(int i=0;i<n;i++){
            if(arr[i]>mid){
                return false;
            }
            if(timesum+arr[i]>mid){
                c++;
                timesum=arr[i];
            
                if(c>K){
                    return false;
                }    
            }
            else{
                timesum+=arr[i];
            }
        }
        return true;
    }
  public:
    long long minTime(int arr[], int n, int k)
    {
        long long start=0;
        long long end=0;
     for(int i=0;i<n;i++){
        end +=arr[i];
     }
        long long ans=-1;
        while(start<=end){
            long long mid=start +(end-start)/2;
            if(ispossiblesolution(arr,n,k,mid)){
                ans=mid;
                end=mid-1;
                
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
}
