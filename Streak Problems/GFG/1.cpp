// Given a string, s, the objective is to convert it into integer format without utilizing any built-in functions. If the conversion is not feasible, the function should return -1.

// Example 1:

// Input:
// s = "-123"
// Output: 
// -123
// Explanation:
// It is possible to convert -123 into an integer 
// and is so returned in the form of an integer

class Solution{
   public:
    int atoi(string str) {
        int ans = 0, flag = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '-' && i == 0){
                flag = 1;
                continue;
            } 
            if (str[i] >= '0' && str[i] <= '9'){
                ans = ans * 10 + (str[i] - '0');
            }
            else{
                return -1;
            }
        }
        if(flag) ans = -(ans);
        return ans;
    }
};
