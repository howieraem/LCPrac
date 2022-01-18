/*
 * @lc app=leetcode id=1231 lang=cpp
 *
 * [1231] Divide Chocolate
 */
#include <algorithm>
#include <climits>
#include <vector>

using std::min;
using std::vector;

// @lc code=start
class Solution {
public:
    // Similar questions: Q410 and Q1101
    // T: O(n * log(sum / k)), sum := sum(sweetness)
    // S: O(1)
    int maximizeSweetness(vector<int>& sweetness, int k) {
        k++;  // include yourself, k + 1 pieces
        // l = min(sweetness), r = sum(sweetness)
        int l = INT_MAX, r = 0;
        for (const auto &s : sweetness) {
            l = min(l, s);
            r += s;
        }

        // Binary search, upper_bound?
        while (l <= r) {
            int m = l + ((r - l) >> 1);
            if (nSplit(sweetness, m) < k) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    }

private:
    static int nSplit(vector<int> &ss, int minSweet) {
        int cnt = 0, sweet = 0;
        for (const int& s : ss) {
            sweet += s;
            if (sweet >= minSweet) {
                // split
                ++cnt;
                sweet = 0;
            }
        }
        return cnt;
    }
};
// @lc code=end

