// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    int n = a.size();
    if(n==0) return 0;

    unordered_set<int> st;
    for(int i=0;i<n; i++){
        st.insert(a[i]);
    }

    int cnt=0,x=0, longest=0;

    for(auto it: st){
        if(st.find(it-1)==st.end()){
            x= it;
            cnt = 1;

            while (st.find(x + 1) != st.end()) {
              cnt++;
              x = x + 1;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;
}


//                       OR                     //

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==0)
        return 0;
  int cnt  = 1;
  int maxi= 1;
       for(int i = 1; i<nums.size(); i++){
           if(nums[i]!=nums[i-1]){
               if(nums[i]-nums[i-1]==1){
                   cnt++;
               }
               else{
                   maxi= max(maxi,cnt);
                   cnt=1;
                   
               }
           }
       }
       return max(maxi,cnt);
    }
};
