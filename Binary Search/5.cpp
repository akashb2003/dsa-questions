// You’re given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
// The floor of x is the largest element in the array which is smaller than or equal to x.
// The ceiling of x is the smallest element in the array greater than or equal to x.

// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
// Result: 4 7
// Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

// Example 2:
// Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
// Result: 8 8
// Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int low = 0, high = n-1, mid = low + (high - low)/2;
	int floorV = -1, ceileV = -1;
	while(low<= high){
		if(a[mid]==x){
			return {a[mid], a[mid]};
		}
		else if(a[mid]<x){
			floorV = a[mid];
			low = mid+1;
		}
		else{
			ceileV = a[mid];
			high = mid -1;
		}
		mid = low + (high - low)/2;
	}

	return {floorV, ceileV};
}
