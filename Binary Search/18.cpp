// You are given an integer array bloomDay, an integer m and an integer k.

// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

// Example 1:

// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
// We need 3 bouquets each should contain 1 flower.
// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

class Solution {
public:

    int calcBuk(int mid, vector<int>& bloomDay, int k){
        int ans =0, cnt=0;

        for(int i=0; i< bloomDay.size(); i++){
            if(mid >= bloomDay[i]) cnt++;
            else{
                ans += cnt/k;
                cnt = 0;
            }
        }
        ans += cnt/k;
        return ans;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long val = m* 1ll * k *1ll;

        if(bloomDay.size() < val) return -1;

        int l = bloomDay[0], h = bloomDay[0];

        for(int i=1; i< bloomDay.size(); i++){
            l = min(l, bloomDay[i]);
            h = max(h, bloomDay[i]);
        }
        
        int mid = l+(h-l)/2;
        while(l<h){

            int numBuks = calcBuk(mid, bloomDay, k);

            if( numBuks < m){
               l = mid+1;
            }
            else h = mid;

            mid = l+(h-l)/2;
        }
        return l;
    }
};
