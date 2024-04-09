// Given an array of n elements, where each element is at most k away from its target position, you need to sort the array optimally.

// Example 1:

// Input:
// n = 7, k = 3
// arr[] = {6,5,3,2,8,10,9}
// Output: 2 3 5 6 8 9 10
// Explanation: The sorted array will be
// 2 3 5 6 8 9 10

class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int k){
        // Your code here
        priority_queue<int, vector<int>, greater<int>>pq;
        int i=0;
        vector<int>ans;
        while(i<num){
            while(pq.size()>k){
                ans.push_back(pq.top());
                pq.pop();
            }
            pq.push(arr[i]);
            i++;
        }
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
