// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:

    int left_most(vector<int>& nums, int target,int n){
            int ans=-1;
            int s=0, e = n-1, m = s+(e-s)/2;

            while(s<=e){
                if(nums[m]==target){
                    ans = m;
                    e = m-1;
                }
                else if(nums[m]>target){
                    e=m-1;
                }
                else if(nums[m]<target){
                    s=m+1;
                }

                m = s+(e-s)/2;
            }

            return ans;

        }

        int right_most(vector<int>& nums, int target,int n){
            int ans=-1;
            int s=0, e = n-1, m = s+(e-s)/2;

            while(s<=e){
                if(nums[m]==target){
                    ans = m;
                    s = m+1;
                }
                else if(nums[m]>target){
                    e=m-1;
                }
                else if(nums[m]<target){
                    s=m+1;
                }

                m = s+(e-s)/2;
            }

            return ans;

        }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int>ans;
        ans.push_back(left_most(nums,target, nums.size()));
        ans.push_back(right_most(nums,target, nums.size()));
        return ans;
    }
};
