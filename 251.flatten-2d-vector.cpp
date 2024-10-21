/*
 * @lc app=leetcode id=251 lang=cpp
 *
 * [251] Flatten 2D Vector
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
// Intuitive solution: flatten the 2D vector and check if indices out of bound (not constant space)

// S: O(1)
class Vector2D {
    vector<vector<int>>::iterator row_it, row_end;
    vector<int>::iterator col_it;

public:
    // T: O(1)
    Vector2D(vector<vector<int>>& vec) {
        row_it = vec.begin();
        row_end = vec.end();
        if (row_it != row_end) {
            col_it = row_it->begin();
        }
    }
    
    // T: O(n) worse
    int next() {
        hasNext();  // in case col_it has reached row_it->end(), i.e. col_end
        return *col_it++;
    }
    
    // T: O(n) worse
    bool hasNext() {
        // Use `while` rather than `if` in case next row/list is empty 
        while (col_it == row_it->end() && row_it != row_end) {
            ++row_it;
            if (row_it != row_end) {
                col_it = row_it->begin();
            }
        }
        return row_it != row_end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

