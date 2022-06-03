/*
 * @lc app=leetcode id=364 lang=cpp
 *
 * [364] Nested List Weight Sum II
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
    /*
    // Solution 1: modified from Q339, intuitive
    // T: O(n)
    // S: O(n)
    int depthSumInverse(std::vector<NestedInteger>& nestedList) {
        int max_depth = 0;
        std::queue<NestedInteger, std::deque<NestedInteger>> q(std::deque<NestedInteger>(nestedList.begin(), nestedList.end()));
        std::vector<std::vector<int>> lvls;

        while (q.size()) {
            int qs = q.size();
            lvls.push_back({});
            while (qs--) {
                NestedInteger ni = q.front(); q.pop();
                if (ni.isInteger()) {
                    lvls.back().push_back(ni.getInteger());
                } else {
                    for (const auto &inner : ni.getList()) {
                        q.push(inner);
                    }
                }
            }
            ++max_depth;
        }

        int ans = 0;
        for (int d = 0; d < lvls.size(); ++d) {
            for (const int &x : lvls[d]) {
                ans += x * (max_depth - d);
            }
        }

        return ans;
    }
    */

    // Solution 2: without multiplying by depths. 
    // Each integer gets added one extra time for the mere existence of 
    // each one level under it.
    // T: O(n)
    // S: O(n)
    int depthSumInverse(std::vector<NestedInteger>& nestedList) {
        int singles_sum = 0, ans = 0;
        std::queue<std::vector<NestedInteger>> q;
        q.push(nestedList);

        while (q.size()) {
            int qs = q.size();
            while (qs--) {
                auto vec_ni = q.front(); q.pop();
                for (const auto &ni : vec_ni) {
                    if (ni.isInteger()) {
                        singles_sum += ni.getInteger();
                    } else {
                        q.push(ni.getList());
                    }
                }
            }
            ans += singles_sum;
        }
        return ans;
    }
};
// @lc code=end

