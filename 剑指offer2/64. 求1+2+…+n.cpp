class Solution {
public:
    int sumNums(int n) {
        // Method 1: use math.pow()
        // return ((int)pow(n,2) + n) >> 1;

        // Method 2: recursive, with handling n = 0
        n && (n += sumNums(n - 1));     // n = 0 if n == 0 else n + sumNums(n - 1)
        return n;
    }
};
