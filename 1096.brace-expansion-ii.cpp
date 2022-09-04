/*
 * @lc app=leetcode id=1096 lang=cpp
 *
 * [1096] Brace Expansion II
 */
#include <bits/stdc++.h>

using std::stack;
using std::string;
using std::unordered_set;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n ^ 2) due to string copying and product of sets, n := len(expression)
    // S: O(n)
    vector<string> braceExpansionII(string expression) {
        stack<unordered_set<string>> stk;
        unordered_set<string> set1, set2;

        for (const char& c : expression) {
            if ('a' <= c && c <= 'z') {
                if (set2.size()) {
                    // add char c to each string in set2
                    unordered_set<string> tmp;
                    for (const auto& s : set2) {
                        string t(s);
                        t.push_back(c);
                        tmp.insert(std::move(t));
                    }
                    set2 = std::move(tmp);
                } else {
                    // initialize set2
                    string s = {c};
                    set2.insert(std::move(s));
                }
            } else if (c == '{') {
                stk.push(std::move(set1));  // also clears set1
                stk.push(std::move(set2));  // also clears set2
            } else if (c == '}') {
                auto pre_set2 = stk.top(); stk.pop();
                auto pre_set1 = stk.top(); stk.pop();
                for (const auto& s : set2) {
                    set1.insert(s);
                }
                set2 = product(pre_set2, set1);
                set1 = std::move(pre_set1);
            } else if (c == ',') {
                for (const auto& s : set2) {
                    // union of 2 sets
                    set1.insert(s);
                }
                set2.clear();
            }
        }
        // Don't forget the last batch of strings
        for (const auto& s : set2) {
            set1.insert(s);
        }

        vector<string> res(set1.cbegin(), set1.cend());
        std::sort(res.begin(), res.end());
        return res;
    }

private:
    unordered_set<string> product(unordered_set<string>& set1, unordered_set<string>& set2) {
        if (set1.empty()) {
            return set2;
        } else if (set2.empty()) {
            return set1;
        }

        unordered_set<string> res;
        for (const auto& s1 : set1) {
            for (const auto& s2 : set2) {
                res.insert(s1 + s2);
            }
        }
        return res;
    }
};
// @lc code=end

