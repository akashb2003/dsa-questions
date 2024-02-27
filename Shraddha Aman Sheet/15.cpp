// Given an array arr[] of distinct elements size N that is sorted and then rotated around an unknown point, the task is to check if the array has a pair with a given sum X.

// Examples : 

// Input: arr[] = {11, 15, 6, 8, 9, 10}, X = 16
// Output: true
// Explanation: There is a pair (6, 10) with sum 16

// Input: arr[] = {11, 15, 26, 38, 9, 10}, X = 35
// Output: true
// Explanation: There is a pair (26, 9) with sum 35

// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// This function returns true if arr[0..n-1]
// has a pair with sum equals to x.
bool pairInSortedRotated(int arr[], int n, int x)
{
	// Find the pivot element
	int i;
	for (i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
			break;

	// l is now index of smallest element
	int l = (i + 1) % n;

	// r is now index of largest element
	int r = i;

	// Keep moving either l or r till they meet
	while (l != r) {

		// If we find a pair with sum x,
		// we return true
		if (arr[l] + arr[r] == x)
			return true;

		// If current pair sum is less,
		// move to the higher sum
		if (arr[l] + arr[r] < x)
			l = (l + 1) % n;

		// Move to the lower sum side
		else
			r = (n + r - 1) % n;
	}
	return false;
}
