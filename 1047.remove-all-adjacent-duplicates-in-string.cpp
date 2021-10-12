/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    // In C++, pop operation can be done on std::string. No need to use 
    // an auxillary std::stack.
    string removeDuplicates(string s) {
        string res = "";
        for (char& c : s) {
            if (res.size() && c == res.back())  res.pop_back();
            else  res.push_back(c);
        }
        return res;
    }
};
// @lc code=end

