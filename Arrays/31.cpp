//Longest Successive Elements

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
