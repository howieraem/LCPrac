/*
 * @lc app=leetcode id=809 lang=cpp
 *
 * [809] Expressive Words
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(len(s) + sum(len(w) for w in words))
    // S: O(1)
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        const int l = s.size();

        for (const auto &w : words) {
            int k = w.size();
            if (k <= l) {     // prune
                int i = 0, j = 0;

                while (i < k && j < l) {
                    if (w[i] != s[j])  break;
                    int w_repeat_cnt = 1, s_repeat_cnt = 1;

                    while (i < k - 1 && w[i] == w[i + 1]) {
                        ++w_repeat_cnt;
                        ++i;
                    }

                    while (j < l - 1 && s[j] == s[j + 1]) {
                        ++s_repeat_cnt;
                        ++j;
                    }

                    if (w_repeat_cnt > s_repeat_cnt || (w_repeat_cnt != s_repeat_cnt && s_repeat_cnt < 3)) {
                        // Case 1 example: w "aaaa", s "aaa"
                        // Case 2 example: w "b", s "bb"
                        break;
                    }
                    ++i; ++j;
                }

                ans += (i == k && j == l);
            }
        }
        return ans;
    }
};
// @lc code=end

