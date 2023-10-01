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

// Return the number in Pascal's Triangle of given rows and columns
// Ex: r = 2, c = 1. 
// Output = 2

int answer(int r, int c){
  // answer is nCr where n = r-1, r = c-1
  int nCr(int n, int r){
      for(int i=0; i< r ; i++){
          ans = ans * (n-i);
          ans = ans/ (i+1);
      }
  }

  int ans = nCr(r-1, c-1);

  return ans;
}
  
