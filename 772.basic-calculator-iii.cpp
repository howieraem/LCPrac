/*
 * @lc app=leetcode id=772 lang=cpp
 *
 * [772] Basic Calculator III
 */
#include <bits/stdc++.h>

using std::stack;
using std::string;
using std::vector;

// @lc code=start
class Solution {
    bool delim(const char& c) {
        return c == ' ';
    }

    bool is_op(const char& c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    int priority(const char& op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return -1;
    }

    void process_op(stack<int>& operands, const char& op) {
        int b = operands.top(); operands.pop();
        int a = operands.top(); operands.pop();
        switch (op) {
            case '+': operands.push(a + b); break;
            case '-': operands.push(a - b); break;
            case '*': operands.push(a * b); break;
            case '/': operands.push(a / b); break;
        }
    }

public:
    // Iterative solution
    // T: O(n)
    // S: O(n)
    int calculate(string s) {
        stack<int> operands;
        stack<char> operators;

        int i = 0;
        while (i < s.size()) {
            if (delim(s[i])) {
                ++i;
                continue;
            }

            if (s[i] == '(') {
                operators.push('(');
                ++i;
            } else if (s[i] == ')') {
                while (operators.top() != '(') {
                    // evaluate the expression within a pair of parentheses
                    process_op(operands, operators.top());
                    operators.pop();
                }
                operators.pop();  // pop the last '(' as well
                ++i;
            } else if (is_op(s[i])) {
                char cur_op = s[i];
                while (!operators.empty() && priority(operators.top()) >= priority(cur_op)) {
                    // apply '*' and '/' before '+' and '-'
                    process_op(operands, operators.top());
                    operators.pop();
                }
                operators.push(cur_op);  // IMPORTANT: for next round of evaluation
                ++i;
            } else {
                int number = 0;
                while (i < s.size() && isalnum(s[i])) {
                    number *= 10;
                    number += s[i] - '0';
                    ++i;
                }
                operands.push(number);
            }
        }

        // IMPORTANT: process the last components
        while (!operators.empty()) {
            process_op(operands, operators.top());
            operators.pop();
        }
        return operands.top();
    }

    /*
    // Recursive solution
    // T: O(n), n := len(s)
    // S: O(n)
    int calculate(string s) {
        const int n = s.size();
        int i = 0;
        return helper(s, i, n);
    }

private:
    // DFS with implicit stack(s)
    // Evaluates expression inside a pair of parentheses '(...)'
    static int helper(const string& s, int& i, const int& n) {
        int cur = 0;
        // Default to '+' because if the first number of an expression is positive 
        // then it doesn't have a plus sign
        char pre_op = '+';
        vector<int> nums;

        while (i < n) {
            char c = s[i++];

            if (c == ' ') {
                continue;
            }

            bool is_digit = isdigit(c);
            if (is_digit) {
                cur *= 10;
                cur += (c - '0');
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
            
            if (c == ')') {
                break;
            }
        }

        int ans = 0;
        for (const int& num : nums) {
            ans += num;
        }
        return ans;
    }
    */
};
// @lc code=end

