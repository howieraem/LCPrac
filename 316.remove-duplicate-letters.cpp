/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */
#include <string>

using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n + s)
    string removeDuplicateLetters(string s) {
        bool vis[26] {};
        int cnt[26] {};
        int n_unique_chars = 0;
        for (const char& ch : s) {
            int c = ch - 'a';
            n_unique_chars += !cnt[c];
            ++cnt[c];
        }

        string res;
        res.reserve(n_unique_chars);
        for (const char &ch : s) {
            int c = ch - 'a';
            if (!vis[c]) {
                // Ensure smallest lexigraphical order (mono-stack variant)
                while (res.size() && res.back() > ch && cnt[res.back() - 'a']) {
                    vis[res.back() - 'a'] = false;
                    res.pop_back();   // will add the popped character again later when the order allows
                }
                vis[c] = true;
                res.push_back(ch);
            }
            --cnt[c];
        }
        return res;
    }
};
// @lc code=end

