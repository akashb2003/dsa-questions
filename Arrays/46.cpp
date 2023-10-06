// You have an array of 'N' integers, where each integer is in the range from '1' to 'N'.

// Every integer appears exactly once, except for two integers, "A," which appears twice, and "B," which is missing.

// Your task is to identify 'A' and 'B' and return their values.

// Example 1:

// Input: 'N' = 6, 'A' = [5, 1, 3, 4, 5, 6]

// Output: {5, 2}

class Solution {
public:
    vector<int> findDuplicateAndMissingElements(vector<int> a) {
        // Calculate the size of the vector
        long long n = a.size();

        // Calculate sum and sum of squares using formulas
        long long sn = (n * (n + 1)) / 2;
        long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;

        // Variables to store actual sum and sum of squares
        long long s = 0, s2 = 0;

        // Iterate through the vector to calculate sum and sum of squares
        for (int i = 0; i < n; i++) {
            s += a[i];
            s2 += (long long)a[i] * (long long)a[i];
        }

        // Calculate the differences
        long long val1 = s - sn;
        long long val2 = s2 - s2n;

        // Calculate the missing and repeating numbers
        val2 = val2 / val1;
        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        // Return the result as a vector
        return {(int)x, (int)y};
    }
};
