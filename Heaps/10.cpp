// You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time.

// ​Return the minimum number of intervals required to complete all tasks.

 

// Example 1:

// Input: tasks = ["A","A","A","B","B","B"], n = 2

// Output: 8

// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mp;
        for(auto it: tasks)
            mp[it]++;
        
        priority_queue<int> pq;
        for(auto it: mp)
            pq.push(it.second);
        int time = 0, curr;
        while(!pq.empty()) {
            vector<int> arr;
            curr = 0;
            for(int i=0; i<=n; i++){
                if(!pq.empty()){
                    arr.push_back(pq.top()-1);
                    pq.pop();
                    curr++;
                }
            }
            for(auto it: arr)
                if(it)
                    pq.push(it);
            time += pq.empty() ? curr : n+1;
        }
        return time;
    }
};

// or //

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
     vector<int>freq(26,0);
     for(int i=0;i<tasks.size();i++){
        freq[tasks[i]-'A']++;
    }
    sort(freq.begin(),freq.end(),greater<int>());
    int idle=(freq[0]-1)*n;
         for(int i=1;i<26;i++){
            idle-=min(freq[i],freq[0]-1);
         }
         return tasks.size()+max(0,idle);
         }
};
