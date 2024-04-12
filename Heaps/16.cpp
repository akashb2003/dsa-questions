// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        using pr = pair<int,int>;
        unordered_map<int,int>mp;
        priority_queue<pr, vector<pr>,greater<pr>>pq;

        for(int num:nums){
            mp[num]++;
        }

        for(auto num:mp){
            pq.push(make_pair(num.second, num.first));
            if(pq.size() >k) 
                pq.pop();
        }

        while(!pq.empty()){
            pr tmp = pq.top();
            ans.push_back(tmp.second);
            pq.pop();
        }

        return ans;
    }
};
