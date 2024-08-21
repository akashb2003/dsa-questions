// Given a string str containing alphanumeric characters. The task is to calculate the sum of all the numbers present in the string.

// Example 1:

// Input:
// str = 1abc23
// Output: 24
// Explanation: 1 and 23 are numbers in the
// string which is added to get the sum as
// 24.
class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string s)
    {
    	int num=0,sum=0;
    	for(int i=0;i<s.length();i++){
    	    if(s[i]>='0' && s[i]<='9')
    	        num = num*10 + (s[i]-'0');
    	    else{
    	        sum+=num;
    	        num=0;
    	    }
    	}
    	return sum+num;
    }
};
