// Problem statement
// You are given an array 'arr' of length 'N'.



// You are given 'Q' queries, and for each query, you are given an index(0-based indexing).



// Answer to each query is the number of the strictly greater elements to the right of the given index element.



// You must return an array 'answer' of length ’N’, where ‘answer[i]’ is the answer to the ‘ith’ query.



// Example:
// Input:
// arr = [5, 2, 10, 4], N=4, Q=2, query = [0, 1]
// Output:
// 1 2

vector<int> countGreater(vector<int> &arr, vector<int> &query) {
  int q = query.size();
  int n = arr.size();
  vector<int> ans;
  for (int i = 0; i < q; i++) {
    int temp = 0;
    int qi = query[i];
    for (int j = qi; j < n; j++) {
      if (arr[j] > arr[qi]) {
        temp++;
      }
    }
    ans.push_back(temp);
  }
  return ans;
}
