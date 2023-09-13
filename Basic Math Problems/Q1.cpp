//Find the number of digits 'n' that evenly divide the n
// Ex: 
//     n = 336
//     output: 3, because 3 and 6 both can divide 336 hence 3 is counted twice
//     n = 35
//     output: 1, because in 3 and 5 only 5 can divide 35 evenly, only 5 is counted
// O(log10(n))
int countDigits(int n){
	// Write your code here.
	int cnt =0,rem=0;
	int num = n;
	while(num>0){
		rem = num%10;

		if(rem!=0 && n%rem==0){
			cnt++;
		}

		num = num/10;
	}	
	return cnt;
}
