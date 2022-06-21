/*
 * @lc app=leetcode id=251 lang=cpp
 *
 * [251] Flatten 2D Vector
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
// Intuitive solution: flatten the 2D vector and check if indices out of bound (not constant space)

// T: O(n)
// S: O(1)
class Vector2D {
    vector<vector<int>>::iterator x, x_end;
    vector<int>::iterator y;

public:
    Vector2D(vector<vector<int>>& vec) {
        x = vec.begin();
        x_end = vec.end();
        if (x != x_end) {
            y = x->begin();
        }
    }
    
    int next() {
        hasNext();  // in case y has reached x->end()
        return *y++;
    }
    
    bool hasNext() {
        while (x != x_end && y == x->end()) {
            ++x;
            if (x != x_end) {
                y = x->begin();
            }
        }
        return x != x_end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

