//check prime

#include<iostream>
using namespace std;

int main() {
	// Write your code here
	int n, cnt=0;
	cin>>n;

	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			cnt++;
			if(n/i != i) cnt++;
		}
	}
	if(cnt >2){
		cout<<"false";
	}
	else
	cout<<"true";
	
}
