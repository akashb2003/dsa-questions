// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.

 

// Example 1:

// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"

#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    static bool cmp(const string &a, const string &b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        
        // Convert integers to strings
        for (int num : nums) {
            temp.push_back(to_string(num));
        }

        // Sort the strings using the custom comparator
        sort(temp.begin(), temp.end(), cmp);

        // Check if the result is "0"
        if (temp[0] == "0") {
            return "0";
        }
        // Concatenate the sorted strings
        string ans = "";
        for (const string &num : temp) {
            ans += num;
        }
        return ans;
    }
};
