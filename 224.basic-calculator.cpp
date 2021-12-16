/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */
#include <numeric>
#include <queue>
#include <string>
#include <vector>

using std::accumulate;
using std::queue;
using std::string;
using std::vector;

// @lc code=start
// T: O(l), l := len(s)
// S: O(l)
class Solution {
public:
    int calculate(string s) {
        queue<char> q;
        for (const auto &c : s) {
            q.push(c);
        }
        return helper(q);
    }

private:
    static int helper(queue<char> &q) {
        vector<int> nums;
        char sign = '+';
        int num = 0;

        while (q.size()) {
            char c = q.front(); q.pop();
            bool isDigit = (c >= '0' && c <= '9');
            if (isDigit) {
                num = 10 * num + (c - '0');
            } else if (c == '(') {
                num = helper(q);
            }

            if ((!isDigit && c != ' ') || q.empty()) {
                if (sign == '+') {
                    nums.push_back(num);
                } else if (sign == '-') {
                    nums.push_back(-num);
                }
                num = 0;
                sign = c;
            }

            if (c == ')')  break;
        }
        return accumulate(nums.begin(), nums.end(), decltype(nums)::value_type(0));
    }
};
// @lc code=end

