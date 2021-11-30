class Solution {
public:
    /*
    // Recursive
    int lastRemaining(int n, int m) {
        return n == 1 ? 0 : (m + lastRemaining(n - 1, m)) % n;
    }
    */

    // Iterative
    int lastRemaining(int n, int m) {
        int f = 0;
        for (int i = 2; i <= n; ++i) {
            f = (m + f) % i;
        }
        return f;
    }
};
