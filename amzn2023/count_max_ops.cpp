/**
 * Given strings s and t. If characters from s are all in use,
 * how many t can be reconstructed?
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// T: O(len(s) + len(t) + a), a = 26 lower letters
// S: O(a)
int count_max_ops(const string& s, const string& t) {
    vector<int> s_cnts(26), t_cnts(26);
    for (const auto& c : s) {
        ++s_cnts[c - 'a'];
    }
    for (const auto& c : t) {
        ++t_cnts[c - 'a'];
    }

    int ans = INT_MAX;
    for (int i = 0; i < 25; ++i) {
        if (t_cnts[i]) {
            ans = std::min(ans, s_cnts[i] / t_cnts[i]);
        }
    }
    return ans;
}