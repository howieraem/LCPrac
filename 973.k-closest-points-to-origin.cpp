/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */
#include <algorithm>
#include <random>
#include <vector>

using std::swap;
using std::vector;

// @lc code=start
class Solution {
    static inline int dist(const vector<int> &p) {
        return p[0] * p[0] + p[1] * p[1];
    }

public: 
    // Quick select (heap-based methods can get TLE)
    // T: O(n ^ 2) worst, O(n) best/average
    // S: O(log(n)) average, O(n) worst
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const int n = points.size();
        if (k == n)  return points;

        // Shuffling helps quick sort and quick select
        auto rng = std::default_random_engine {};
        std::shuffle(std::begin(points), std::end(points), rng);
        
        quickSelect(points, 0, n - 1, k);
        points.resize(k);
        return points;
    }

private:
    static void quickSelect(vector<vector<int>>& points, int begin, int end, const int &k) {
        int pivot = dist(points[begin]), l = begin + 1, r = end;
        while (l <= r) {
            if (dist(points[l]) <= pivot) {
                ++l;
                continue;
            }

            if (dist(points[r]) > pivot) {
                --r;
                continue;
            }

            swap(points[l], points[r]);
            ++l;
            --r;
        }

        swap(points[begin], points[r]);
        if (r < k)  quickSelect(points, r + 1, end, k);
        else if (r > k)  quickSelect(points, begin, r - 1, k);
    }
};
// @lc code=end

