/*
 * @lc app=leetcode id=1648 lang=cpp
 *
 * [1648] Sell Diminishing-Valued Colored Balls
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    static const long MOD = 1e9 + 7;

    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.rbegin(), inventory.rend());  // descending
        const int N = inventory.size();
        long cur = inventory[0];
        long ans = 0, i = 0;
        long o = (long) orders;
        while (o > 0) {
            while (i < N && inventory[i] == cur)  ++i;  // duplicates
            long nxt = i == N ? 0 : inventory[i];
            // i is now the number of colors with the same number of balls
            long nums = (cur - nxt) * i;

            // Sum of arithmetic progression:
            // S(n) = a_1 * n + [n * (n - 1) * d] / 2 = n * (a_1 * a_n) / 2
            if (o > nums) {
                ans += (((cur + nxt + 1) * (cur - nxt)) >> 1) * i;
            } else {
                long nColors = o / i;
                ans += (((cur + (cur - nColors) + 1) * nColors) >> 1) * i + (cur - nColors) * (o % i);
            }
            o -= nums;
            ans %= MOD;
            cur = nxt;
        }
        return (int) ans;
    }
};
// @lc code=end

