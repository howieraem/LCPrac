/*
 * @lc app=leetcode id=1776 lang=cpp
 *
 * [1776] Car Fleet II
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        const int n = cars.size();

        // Maintain a stack of cars (indices), where their collision time is strict decreasing.
        stack<int> stk;
        vector<double> res(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            while (stk.size()) {
                int j = stk.top();
                if (cars[i][1] <= cars[j][1] || getCollisionTime(cars[j], cars[i]) >= res[j] && res[j] > 0) {
                    stk.pop();
                } else {
                    break;
                }
            }
            if (stk.size()) {
                int j = stk.top();
                res[i] = getCollisionTime(cars[j], cars[i]);
            }
            stk.push(i);
        }
        return res;
    }

private:
    inline static double getCollisionTime(vector<int> &car1, vector<int> &car2) {
        // (p1 - p2) / (v2 - v1)
        return (double) (car1[0] - car2[0]) / (car2[1] - car1[1]);
    }
};
// @lc code=end

