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

    std::mt19937 gen;
    int _k;

public: 
    Solution() : gen((std::random_device())()) {};

    // Quick select (heap-based methods can get TLE)
    // T: O(n ^ 2) worst, O(n) best/average
    // S: O(log(n)) average, O(n) worst
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const int n = points.size();
        if (k == n)  return points;
        _k = k;
        quickSelect(points, 0, n - 1);
        points.resize(k);
        return points;
    }

private:
    void quickSelect(vector<vector<int>>& points, int begin, int end) {
        // Find a random pivot and move it to the beginning of the array of the subproblem 
        std::uniform_int_distribution<> distrib(begin, end);
        int pivot_idx = distrib(gen);
        swap(points[begin], points[pivot_idx]);
        int pivot = dist(points[begin]);
        
        // Since begin is now the pivot's index, 
        // do the swapping from begin + 1
        int l = begin + 1, r = end;
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

        // Now r should be the new index of pivot, so that numbers on the left
        // are less than or equal to pivot and numbers on the right are greater 
        // than pivot. 
        swap(points[begin], points[r]);

        if (r < _k)  quickSelect(points, r + 1, end);
        else if (r > _k)  quickSelect(points, begin, r - 1);
    }
};
// @lc code=end

