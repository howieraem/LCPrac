/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 */
#include <bits/stdc++.h>

using std::vector;
using std::map;

// @lc code=start
// S: O(n * s), s := the number of snap() called
class SnapshotArray {
    vector<map<int, int>> snaps;
    int snap_id = 0;

public:
    // T: O(n)
    SnapshotArray(int length) : snaps(length) {
        for (int i = 0; i < length; ++i) {
            map<int, int> mp;
            mp[0] = 0;
            snaps[i] = mp;
        }
    }
    
    // T: O(log(s))
    void set(int index, int val) {
        snaps[index][snap_id] = val;
    }
    
    // T: O(1)
    int snap() {
        return snap_id++;
    }
    
    // T: O(log(s))
    int get(int index, int snap_id) {
        auto it = snaps[index].upper_bound(snap_id); it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end

