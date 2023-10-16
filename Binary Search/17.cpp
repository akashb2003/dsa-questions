// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

 

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

class Solution {
public:

    long calcTime(vector<int>& piles, int time, int n){
        long ans=0;
        for(int i=0; i<n;i++){
            ans += ceil((double)piles[i]/(double)time);
        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long max = piles[0];
        int n = piles.size();
        for(int i=1; i<n;i++){
            if(max<piles[i]) max = piles[i];
        }
        
        long low = 1, high = max;
        while(low<= high){
            int m = low + (high - low)/2;
            long time = calcTime(piles,m,n);

            if(time<=h){
                high = m-1;
            }
            else low = m+1;
        }
        return low;
    }
};
