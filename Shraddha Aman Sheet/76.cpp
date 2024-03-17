// You have N books, each with A[i] number of pages. M students need to be allocated contiguous books, with each student getting at least one book.
// Out of all the permutations, the goal is to find the permutation where the sum of maximum number of pages in a book allotted to a student should be minimum, out of all possible permutations.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

 

// Example 1:

// Input:
// N = 4
// A[] = {12,34,67,90}
// M = 2
// Output:113
// Explanation:Allocation can be done in 
// following ways:
// {12} and {34, 67, 90} Maximum Pages = 191
// {12, 34} and {67, 90} Maximum Pages = 157
// {12, 34, 67} and {90} Maximum Pages =113.
// Therefore, the minimum of these cases is 113,
// which is selected as the output.

class Solution 
{
    public:
    //To find the if the allocation is possible or not
    bool ispossible(int arr[],int n,int m,int mid)
    {
        int pagecount = 0; // page count allocated 
        int studentcount = 1; // initial student count
        for(int i=0;i<n;i++)
        {
            if(pagecount + arr[i] <= mid ) //checking of mid condition
            {
                pagecount += arr[i]; 
            }
            else
            {
                studentcount++;
                if(studentcount>m || arr[i]>mid)
                {
                    return false;
                }
                pagecount = arr[i];
            }
        }
        return true;
    }

    //Main function
    int findPages(int A[], int N, int M) 
    {
        if(N<M) // if no of books are already less than student allocation isn't possible(edge case)
        {
            return -1;
        }
        int s =0; //start 
        int e = accumulate(A,A+N,0); // sum of all the pages of books
        int ans = -1;
        int mid = s + (e-s)/2; // finding the mid of pages then put the stamp there and compare to check the minimum of allocation 
        while(s<=e) //  binary search approach
        {
            if(ispossible(A,N,M,mid))
            {
                ans = mid;
                e = mid-1;
            }
            else
            {
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }

};
