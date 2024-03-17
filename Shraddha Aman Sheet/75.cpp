// Problem statement
// You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.



// You are also given an integer 'k' which denotes the number of aggressive cows.



// You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.



// Print the maximum possible minimum distance.



// Example:
// Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}

// Output: 2

bool possible(vector<int>& stalls,int m,int k){
    int pre_cow_pos=stalls[0];
    int no_of_cows=1;
    for(auto val:stalls){
        if(val-pre_cow_pos>=m){
            pre_cow_pos=val;
            no_of_cows++;
        }

        if(no_of_cows==k) return true;

    }

    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int n=stalls.size();
    int s=stalls[1]-stalls[0];
    int e=stalls[n-1]-stalls[0]; 
    int ans=s;
    int m;
    while(s<e){
        m=(e-s)/2+s;
        if(possible(stalls,m,k)){
            ans=m;
            s=m+1;
        }else e=m;
    }

    //check for s==e
    if(possible(stalls,s,k)) ans=s;
    return ans;
}
