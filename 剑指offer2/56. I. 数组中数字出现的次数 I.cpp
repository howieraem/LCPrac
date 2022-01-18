class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int x = 0;
        for (auto &n : nums) {
            x ^= n;
        }

        // Let the final answer be {a, b}. Then a ^ b = x.
        // Split all numbers into two groups, such that
        // one group contains `a` and another contains
        // `b`. In each group, all other numbers appear
        // exactly either twice or zero time.
        // Find the split point by finding the first bit 1 in x.
        // The idea here is that the 0 bits of x indicates where
        // a and b are equal, and the 1 bits indicates where a 
        // and b are unequal. We can find any bit 1 in x to split 
        // the array into two groups.
        int split = 1;
        while (!(split & x)) {
            split <<= 1;
        }

        int a = 0, b = 0;
        for (auto &n : nums) {
            if (split & n)  a ^= n;
            else  b ^= n;
        }
        return {a, b};
    }
};
