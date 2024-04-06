// Problem statement
// There are ‘N’ people at a party. Each person has been assigned a unique id between 0 to 'N' - 1(both inclusive). A celebrity is a person who is known to everyone but does not know anyone at the party.

// Given a helper function ‘knows(A, B)’, It will returns "true" if the person having id ‘A’ know the person having id ‘B’ in the party, "false" otherwise. Your task is to find out the celebrity at the party. Print the id of the celebrity, if there is no celebrity at the party then print -1.

#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
	stack<int>st;
	for(int i=0; i<n; i++){
		st.push(i);
	}

	while(st.size()>1){
		int id1 = st.top();
		st.pop();
		int id2 = st.top();
		st.pop();
		
		if(knows(id1, id2)) st.push(id2);
		else st.push(id1);
	}
	int cel = st.top();
	bool everyoneKnows = true,  knowsAnyone = false;

	for(int i=0; i<n;i++){
		if(i!=cel && !knows(i,cel)){
			everyoneKnows = false;
			break;
		}
	}
	//cel dont know anyone
	for(int i=0;i<n;i++){
		if(knows(cel, i)){
			knowsAnyone = true;
			break;
		}

	}

	if(knowsAnyone || !everyoneKnows){
		cel  = -1;
	}

	return cel;
}
