/*

Pascal's Triangle:

          1
        1   1
      1   2   1
    1   3   3   1
  1   4   6   4   1
1   5  10  10   5   1

array = [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1].........]

*/

// Print the entire row of Pascal's Triangle:
// Ex: Input: 4, Output: [1,3,3,1]

void printRow(int r){
  int ans =1;
  for(int i-1; i< r; i++){
    ans = ans*(n - i);
    ans = ans / i;
    cout<< ans;
  }
}
