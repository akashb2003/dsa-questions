// Follow this link for the question, because the questions contain images
// https://leetcode.com/problems/number-of-flowers-in-full-bloom/

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=people.size(),m=flowers.size();
        vector<int> open(m),closed(m),ans(n);
        for(int i=0;i<m;++i)
        open[i]=flowers[i][0],closed[i]=flowers[i][1];
        sort(open.begin(),open.end());
        sort(closed.begin(),closed.end());
        for(int i=0;i<n;++i)
        {
            int lb1=upper_bound(open.begin(),open.end(),people[i])-open.begin();
            int lb2=lower_bound(closed.begin(),closed.end(),people[i])-closed.begin();
            ans[i]=lb1-lb2;
        }
        return ans;
    }
};
