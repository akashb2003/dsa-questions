// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

// Given the integer array position and the integer m. Return the required force.

// Example 1:

// Input: position = [1,2,3,4,7], m = 3
// Output: 3
// Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
// Example 2:

// Input: position = [5,4,3,2,1,1000000000], m = 2
// Output: 999999999
// Explanation: We can use baskets 1 and 1000000000.


class Solution {
public:

    bool isPossible(int gap, int m, vector<int>& position){
        int ballCount = 1, lastBall = position[0], n=position.size();

        for(int i=0; i< n; i++){
            if(position[i]-lastBall >= gap){
                ballCount++;
                lastBall = position[i];
            }
             if(ballCount >= m) return true;
        }
       
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int max = position[n-1];
        int min = position[0];
        
        int l=1, h = max-min;

        while(l<=h){
            int gap = l+(h-l)/2;
            if(isPossible(gap,m,position)){
                l = gap+1;
            }
            else h = gap-1;
        }

        return h;

    }
};
