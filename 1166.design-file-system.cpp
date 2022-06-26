/*
 * @lc app=leetcode id=1166 lang=cpp
 *
 * [1166] Design File System
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class FileSystem {
    std::unordered_map<string, int> mp;

public:
    FileSystem() {
        mp[""] = -1;
    }
    
    // T: O(len(path))
    bool createPath(string path, int value) {
        int idx = path.find_last_of('/');
        string parent = path.substr(0, idx);
        if (mp.find(parent) == mp.end() || mp.find(path) != mp.end()) return false;
        mp[path] = value;
        return true;
    }
    
    // T: O(1)
    int get(string path) {
        return mp.find(path) != mp.end() ? mp[path] : -1; 
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
// @lc code=end

