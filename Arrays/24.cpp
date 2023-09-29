// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        return (nums[nums.size()/2]);

    }
};

//        or        //

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> cnt;
        int n =nums.size();
        for(int i=0;i<n;i++){
            cnt[nums[i]]++;
        }
        int ans=0;
        
        for(auto it: cnt){
            if(it.second> n/2)
            {ans = it.first;
            break;
            }
        }
        return ans;
    }
};
