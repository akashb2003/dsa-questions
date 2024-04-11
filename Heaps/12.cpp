// Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

// Example 1:

// Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
// Example 2:

// Input: hand = [1,2,3,4,5], groupSize = 4
// Output: false
// Explanation: Alice's hand can not be rearranged into groups of 4.

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int,vector<int>, greater<int>>pq;
        unordered_map<int,int>mp;
        
        for(auto num:hand){
            mp[num]++;
        }

        for(auto num:mp){
            pq.push(num.first);
        }
        
        while(!pq.empty()){
            int num = pq.top();
            if(mp[num]==0) {
                pq.pop();
                continue;
            }
            mp[num]--;
            int k= groupSize-1;
            while(k>0){
                int nextNum = num+1;
                if(mp[nextNum]>0){
                    mp[nextNum]--;
                    num = nextNum;
                    k--;
                }
                else return false;
            }
        }
        return true;
        
    }
};
