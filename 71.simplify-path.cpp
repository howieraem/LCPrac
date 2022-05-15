/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
    std::vector<std::string> str_split(const string &s, char delim) {
        std::vector<std::string> res;
        std::stringstream ss(s);
        std::string item;

        while (std::getline(ss, item, delim)) {
            res.push_back(item);
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

public:
    /*
    // Solution 1: with auxiliary string functions
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
    */

    // Solution 2 (more intuitive, easier to write)
    // T: O(n)
    // S: O(n)
    std::string simplifyPath(std::string path) {
        std::vector<std::string> st;
        for (int i = 0; i < path.size(); ++i) {
            if (path[i] == '/') {
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
                if (st.size()) {
                    st.pop_back();
                }
            } else {
                st.push_back(tmp);
            }
        }

        std::string res;
        for (int i = 0; i < st.size(); ++i) {
            res.push_back('/');
            res += st[i];
        }
        return res.empty() ? "/" : res;
    }
};
// @lc code=end
