// Given an array of n distinct integers. The task is to check whether reversing any one sub-array can make the array sorted or not. If the array is already sorted or can be made sorted by reversing any one subarray, print “Yes“, else print “No“.

// Examples: 

// Input : arr [] = {1, 2, 5, 4, 3}
// Output : Yes
// By reversing the subarray {5, 4, 3}, the array will be sorted.

// Input : arr [] = { 1, 2, 4, 5, 3 }
// Output : No

#include <bits/stdc++.h> 
using namespace std; 

bool sortArr(int a[], int n) 
{ 
	int x = -1; 
	int y = -1; 

	for (int i = 0; i < n - 1; i++) { 
		if (a[i] > a[i + 1]) { 
			if (x == -1) { 
				x = i; 
			} 
			y = i + 1; 
		} 
	} 

	if (x != -1) { 
		reverse(a + x, a + y + 1); 
		for (int i = 0; i < n - 1; i++) { 
			if (a[i] > a[i + 1]) { 
				return false; 
				return 0; 
			} 
		} 
	} 

	return true; 
} 

// Driver Program 
int main() 
{ 
	int arr[] = { 1, 2, 5, 4, 3 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	sortArr(arr, n) ? (cout << "Yes" << endl) 
					: (cout << "No" << endl); 
	return 0; 
} 

//This code is contributed by Shaurya Dixit (B19EE077)
