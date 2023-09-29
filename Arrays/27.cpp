// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should rearrange the elements of nums such that the modified array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        
        int n=  a.size();
        vector<int>ans(n,0);
        int pv =0, ng=1;

        for(int i =0; i< n; i++){
            if(a[i]>0){
                ans[pv] = a[i];
                pv+=2;
            }
            else{
                ans[ng] = a[i];
                ng +=2;
            }
        }
        
        return ans;
    }
};
