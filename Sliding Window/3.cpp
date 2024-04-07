// There are ‘n’ fruit trees that are planted along a road. The trees are numbered from 0 to n-1. The type of fruit each tree bears is represented by an integer from 1 to 'n'.



// A Ninja is walking along that road. He has two baskets and wants to put the maximum number of fruits in them. The restriction is that each basket can have only one type of fruit.



// Ninja can start with any tree and end at any tree, but once he has started, he cannot skip a tree i.e if he picks fruit from the tree ‘i’, then he has to pick fruit from tree ‘i+1’ before going to the tree ‘i+2’. He will pick one fruit from each tree until he cannot, i.e, he will stop when he has to pick a fruit of the third type because only two different fruits can fill both baskets.



// You are given an array ‘arr’. The ‘i’th integer in this array represents the type of fruit tree ‘i’ bears. Return the maximum number of fruits Ninja can put in both baskets after satisfying all the conditions.



// For Example:
//  'arr' = [1, 2, 3]

//  Here, we have three different types of fruits. We can pick [1, 2] or [2, 3]. We can pick a maximum of two fruits.

// Hence, we return 2.

int findMaxFruits(vector<int> &arr, int n) {
    // Write your code here.
    int l=0,r=0, basket = 2;
    int ans=0;
    unordered_map<int,int>mp;

    while(r<n){
        mp[arr[r]]++;
        while(mp.size()>basket){
            mp[arr[l]]--;
            if(mp[arr[l]]==0) mp.erase(arr[l]);
            l++;
        }
        ans = max(ans,r-l+1);
        r++;
    }
    return ans;
}
