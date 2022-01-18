/*
 * @lc app=leetcode id=1823 lang=cpp
 *
 * [1823] Find the Winner of the Circular Game
 */

// @lc code=start
class Solution {
public:
    // Josephus Problem
    /*
    // Solution 1: bottom-up
    // T: O(n)
    // S: O(1)
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            ans = (ans + k) % i;
        }
        return ans + 1;     // add 1 as player indexes start from 1
    }
    */

    // Solution 2: top-bottom
    // T: O(n)
    // S: O(n) (O(1) if optimized to tail recursion by the compiler)
    int findTheWinner(int n, int k) {
        return n == 1 ? 1 : ((k + findTheWinner(n - 1, k) - 1) % n + 1);    // add 1 as player indexes start from 1
    }
};
// @lc code=end

