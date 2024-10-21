/*
 * @lc app=leetcode id=281 lang=cpp
 *
 * [281] Zigzag Iterator
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
// S: O(m), m := no. of lists, m = 2
class ZigzagIterator {
    vector<vector<int>::iterator> cur_its;
    vector<vector<int>::iterator> ends;
    int p;  // selects the current list

public:
    // T: O(1)
    ZigzagIterator(vector<int>& v1, vector<int>& v2) : cur_its(2), ends(2), p(0) {
        cur_its[0] = v1.begin();
        cur_its[1] = v2.begin();
        ends[0] = v1.end();
        ends[1] = v2.end();
    }

    // T: O(1)
    int next() {
        int x;
        if (cur_its[p] != ends[p]) {
            x = *cur_its[p]++;
            p = 1 - p;  // or p = (p + 1) % n_lists
        } else {
            p = 1 - p;  // or p = (p + 1) % n_lists
            x = *cur_its[p]++;
        }
        return x;
    }

    // T: O(m)
    bool hasNext() {
        for (int i = 0; i < cur_its.size(); ++i) {
            if (cur_its[i] != ends[i]) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

