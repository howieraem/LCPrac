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

struct pt_hash {
    auto operator()(const pt& p) const {
        return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
    }
};

class DetectSquares {
    unordered_map<pt, int, pt_hash> pt_cnts;

public:
    DetectSquares() {}
    
    // T: O(1)
    void add(vector<int> point) {
        pt p(std::ref(point[0]), std::ref(point[1]));
        ++pt_cnts[p];
    }
    
    // T: O(n)
    int count(vector<int> point) {
        const int &x1 = point[0], &y1 = point[1];
        int ans = 0;
        for (const auto& [p3, p3_cnt] : pt_cnts) {
            const auto& [x3, y3] = p3;
            int dx = abs(x3 - x1), dy = abs(y3 - y1);
            if (dx != 0 && dx == dy) {
                // Found a valid diagonal, count the number of squares by calculating 
                // the number of existing antidiagonals
                auto p2_it = pt_cnts.find({x1, y3}), p4_it = pt_cnts.find({x3, y1});
                if (p2_it != pt_cnts.end() && p4_it != pt_cnts.end()) {
                    ans += p3_cnt * p2_it->second * p4_it->second;
                }
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

