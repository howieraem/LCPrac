/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
public:
    // Solution 1
    // T: O(n)
    // S: O(n)
    std::string simplifyPath(std::string path) {
        // stores directories and simulates going back to previous directory
        std::vector<std::string> st;

        int i = 0;
        while (i < path.size()) {
            if (path[i] == '/') {
                ++i;
                continue;
            }

            // Iterate until the next '/'
            std::string tmp;
            while (i < path.size() && path[i] != '/') {
                // Append directory char
                tmp += path[i++];
            }

            if (tmp == ".") {
                continue;
            } else if (tmp == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(std::move(tmp));
            }
            
            ++i;
        }

        std::string res;
        for (i = 0; i < st.size(); ++i) {
            res.push_back('/');
            res.append(std::move(st[i]));
        }
        return res.empty() ? "/" : res;
    }

    /*
    // Solution 2: with auxiliary string functions
    // T: O(n)
    // S: O(n)
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stk;
        std::vector<std::string> parts = str_split(path, '/');
        for (const auto &part : parts) {
            if (part == "..") {
                if (stk.size()) {
                    stk.pop_back();
                }
            } else if (part.size() && part != ".") {
                stk.push_back(part);
            }
        }
        
        return "/" + str_join(stk, "/");
    }

    std::vector<std::string> str_split(const string &s, char delim) {
        std::vector<std::string> res;
        std::stringstream ss(s);
        std::string item;

        while (std::getline(ss, item, delim)) {
            res.push_back(std::move(item));
        }
        return res;
    }

    std::string str_join(std::vector<std::string> substrs, const string &delim) {
        std::stringstream s;
        std::copy(substrs.begin(), substrs.end(), std::ostream_iterator<std::string>(s, delim.c_str()));
        std::string res = s.str();
        if (res.size()) {
            // removes the trailing delimiter
            res.pop_back();
        }
        return res;
    }
    */
};
// @lc code=end
