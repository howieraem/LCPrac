/*
 * @lc app=leetcode id=339 lang=cpp
 *
 * [339] Nested List Weight Sum
 */
#include <bits/stdc++.h>

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
    int depthSum(std::vector<NestedInteger>& nestedList) {
        int ans = 0, depth = 1;
        std::queue<NestedInteger, std::deque<NestedInteger>> q(std::deque<NestedInteger>(nestedList.begin(), nestedList.end()));

        while (q.size()) {
            int qs = q.size();
            while (qs--) {
                NestedInteger ni = q.front(); q.pop();
                if (ni.isInteger()) {
                    ans += ni.getInteger() * depth;
                } else {
                    for (const auto &inner : ni.getList()) {
                        q.push(inner);
                    }
                }
            }
            ++depth;
        }
        return ans;
    }
};
// @lc code=end

