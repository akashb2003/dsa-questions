// Problem statement
// You have a 32-bit unsigned integer called 'num' and another integer called 'i'.



// You need to perform the following operations on the 'num' integer based on the value of 'i':



// 1. Get the bit value at the "i"th position of "num".

// 2. Set the bit at the "i"th position of "num".

// 3. Clear the bit at the "i"th position of "num".



// We are starting bits from 1 instead of 0. (1-based)



// For Example:
// N=25  i=3
// Output : 0 29 25

// Bit at the 3rd position from LSB is 0. (1 1 0 0 1)

// The value of the given number after setting the 3rd bit is 29. (1 1 1 0 1)

// The value of the given number after clearing the 3rd bit is 25. (1 1 0 0 1)

vector<int> bitManipulation(int num, int i){
    // Write your code here.
    vector<int>ans;
    int mask = 1<< (i-1);
    //1st
    int temp = num&mask;
    if(temp==0) ans.push_back(0);
    else ans.push_back(1);

    //2nd
    temp = num|mask;
    ans.push_back(temp);

    //3rd
    temp = num& (~mask);
    ans.push_back(temp);

    return ans;
}
