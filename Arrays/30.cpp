//Find leaders in the array. A leader is a element in an array which is greater than all the elements in right of it

vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int>ans;
    int n = a.size(), maxi = a[n-1];
    ans.emplace_back(maxi);

    for(int i=n-2; i>=0;i--){
        if(a[i]>maxi){
            ans.emplace_back(a[i]);
        }
        maxi = max(maxi, a[i]);
    }

    return ans;

}
