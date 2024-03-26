// Problem statement
// You are given an array 'nums' of ‘n’ integers.



// Return all subset sums of 'nums' in a non-decreasing order.



// Note:
// Here subset sum means sum of all elements of a subset of 'nums'. A subset of 'nums' is an array formed by removing some (possibly zero or all) elements of 'nums'.


// For example
// Input: 'nums' = [1,2]

// Output: 0 1 2 3

// Explanation:
// Following are the subset sums:
// 0 (by considering empty subset)
// 1 
// 2
// 1+2 = 3
// So, subset sum are [0,1,2,3].

void solve(vector<int> &num, vector<int> &ans,int ind, int sum){
	if(ind==num.size()){
		ans.push_back(sum);
		return;
	}
	solve(num,ans,ind+1,sum+num[ind]);
	solve(num,ans,ind+1,sum);
}

vector<int> subsetSum(vector<int> &num){
	// Write your code here.
	vector<int>ans;
	solve(num,ans,0,0);
	sort(ans.begin(),ans.end());
	return ans;
}
