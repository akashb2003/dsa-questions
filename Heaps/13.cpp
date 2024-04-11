// Problem statement
// There are given n ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. We need to connect the ropes with minimum cost.

// Sample Input 1:
//     4 4 3 2 6        
// Sample Output 1:
//    29

int minCost(int arr[], int n)
{
	/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
	int cost = 0;
	priority_queue<int,vector<int>, greater<int>>pq(arr,arr+n);
	while(pq.size()!=1){
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		cost += (a+b);
		pq.push(a+b);
	}
	return cost;
}
