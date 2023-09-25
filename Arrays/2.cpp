// Given an array A of size N of integers. Your task is to find the sum of minimum and maximum element in the array.

class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	int max=A[0],min=A[0];
    	
    	for(int i=1;i<N;i++){
    	    if(max<A[i]){
    	        max=A[i];
    	    }
    	    if(min>A[i]){
    	        min=A[i];
    	    }
    	}
    	
    	return max+min;
    }

};
