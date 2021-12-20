/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */
#include <algorithm>
#include <stack>
#include <utility>
#include <vector>

using std::sort;
using std::stack;
using std::pair;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n))
    // S: O(n)
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int n = position.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; ++i) {
            // (position, time needed to reach target ignoring other cars)
            cars.emplace_back(position[i], (double) (target - position[i]) / speed[i]);
        }

        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b){
            return a.first < b.first;
        });     // sort by the first element, i.e. position

        /*
        // Space complexity below is O(n)
        // In Car Fleet II Q1776, a mono stack is needed.
        stack<float> mono;
        for (int i = 0; i < n; ++i) {
            while (mono.size() && cars[i].second >= mono.top()) {
                mono.pop();
            }
            mono.push(cars[i].second);
        }
        return mono.size();
        */

        // Space complexity below is O(1)
        double cur = 0;
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (cars[i].second > cur) {
                cur = cars[i].second;
                ++ans;
            }
        }
        return ans;
    }
};
// @lc code=end

