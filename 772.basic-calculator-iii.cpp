/*
 * @lc app=leetcode id=772 lang=cpp
 *
 * [772] Basic Calculator III
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    int calculate(string s) {
        const int n = s.size();
        int i = 0;
        return helper(s, i, n);
    }

private:
    static int helper(const string &s, int &i, const int &n) {
        int cur = 0;
        char pre_op = '+';
        vector<int> nums;

        while (i < n) {
            char c = s[i++];
            if (c == ' ') continue;

            bool is_digit = isdigit(c);
            if (is_digit) {
                cur = cur * 10 + (c - '0');
            } else if (c == '(') {
                cur = helper(s, i, n);
            }

            // Different from Q227, the condition is i == n rather than i - 1 == n 
            // because i has been incremented above
            if (!is_digit || i == n) {
                // c is one of {'+', '-', '*', '/', ')'}
                if (pre_op == '+') {
                    nums.push_back(cur);
                } else if (pre_op == '-') {
                    nums.push_back(-cur);
                } else if (pre_op == '*') {
                    nums.back() *= cur;
                } else if (pre_op == '/') {
                    nums.back() /= cur;
                }

                cur = 0;
                pre_op = c;
            }
            
            if (c == ')')  break;
        }

        int ans = 0;
        for (const int &num : nums) {
            ans += num;
        }
        return ans;
    }
};
// @lc code=end

