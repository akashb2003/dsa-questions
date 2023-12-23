// Given an array/list of length 'n' where the array/list represents the boards and each element of the given array/list represents the length of each board. Some 'k' numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.

// You are supposed to return the area of the minimum time to get this job done of painting all the 'n' boards under a constraint that any painter will only paint the continuous sections of boards.

// Example:

// Input: arr = [2, 1, 5, 6, 2, 3], k = 2

// Output: 11
  
  int countK(int m,vector<int> &boards){
        int n = boards.size();
        int Kcount =1;
        int totTime = 0;

        for(int i=0; i<n;i++){
            if(totTime + boards[i]<=m){
                totTime += boards[i];
            }
            else{
                totTime = boards[i];
                Kcount++;
            }
        }
        return Kcount;
    }

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int l = *max_element(boards.begin(), boards.end());
    int h = accumulate(boards.begin(), boards.end(), 0);

    while(l<=h){
        int m= l+(h-l)/2;
        int painters = countK(m, boards);
        if(painters>k){
            l = m+1;
        }
        else h = m-1;
    }
    return l;
}
