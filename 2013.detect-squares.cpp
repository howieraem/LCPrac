/*
 * @lc app=leetcode id=2013 lang=cpp
 *
 * [2013] Detect Squares
 */
#include <bits/stdc++.h>

using std::string;
using std::unordered_map;
using std::pair;
using std::vector;

// @lc code=start
typedef pair<int, int> pt;

class DetectSquares {
    unordered_map<long long, int> pt_cnts;
    vector<pt> pts;

    long long convert_pt_to_key(pt p) {
        return (long long)p.first << 32 | p.second;
    }

public:
    DetectSquares() {}
    
    // T: O(1)
    void add(vector<int> point) {
        pt p(point[0], point[1]);
        ++pt_cnts[convert_pt_to_key(p)];
        pts.push_back(std::move(p));
    }
    
    // T: O(n)
    int count(vector<int> point) {
        const int x1 = point[0], y1 = point[1];
        int ans = 0;
        for (const auto& [x3, y3] : pts) {
            int dx = abs(x3 - x1), dy = abs(y3 - y1);
            if (dx != 0 && dx == dy) {
                // found a valid diagonal
                ans += pt_cnts[convert_pt_to_key({x1, y3})] * pt_cnts[convert_pt_to_key({x3, y1})];
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// @lc code=end

