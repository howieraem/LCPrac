/*
 * @lc app=leetcode id=385 lang=cpp
 *
 * [385] Mini Parser
 */
#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::stack;

class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // T: O(n)
    // S: O(n)
    NestedInteger deserialize(const string& s) {
        const int n = s.size();
        stack<NestedInteger> stk;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '[') {
                stk.push(NestedInteger());
            } else if (s[i] == '-' || std::isdigit(s[i])) {
                int sign = 1, num = 0;
                if (s[i] == '-') {
                    sign = -1;
                } else {
                    num = s[i] - '0';
                }

                while (i + 1 < n && std::isdigit(s[i + 1])) {
                    ++i;
                    num = num * 10 + (s[i] - '0');
                }
                NestedInteger ni(num * sign);
                if (stk.size()) stk.top().add(ni);
                else return ni;
            } else if (s[i] == ']') {
                NestedInteger ni = stk.top(); stk.pop();
                if (stk.size()) stk.top().add(ni);
                else return ni;
            }
        }
        return NestedInteger();
    }
};
// @lc code=end

