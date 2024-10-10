#include <bits/stdc++.h>

using std::vector;

// S: O(m * n)
class NumMatrix {
    vector<vector<int>> tree;  // binary indexed tree, efficient 2d data structure to store prefix sums
    vector<vector<int>> vals;
    int m;
    int n;

    /** Returns the prefix sum of [0...row, 0...col] */
    int prefix_sum(int row, int col) {
        int ans = 0;
        for (int i = row; i > 0; i -= (i & (-i))) {
            for (int j = col; j > 0; j -= (j & (-j))) {
                ans += tree[i][j];
            }
        }
        return ans;
    }

public:
    // T: O(m * n)
    NumMatrix(vector<vector<int>>& matrix) : 
            tree(matrix.size() + 1, vector<int>(matrix[0].size() + 1)),
            vals(matrix) {
        m = matrix.size();
        n = matrix[0].size();
        if (m == 0 || n == 0) {
            return;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                tree[i + 1][j + 1] = matrix[i][j];
            }
        }

        // How to update a binary indexed tree: 
        // 1. take 2's complement of the original index
        // 2. do bitwise AND with the original index
        // 3. add the AND result back to the original index
        for (int j = 1; j <= n; ++j) {
            int nj = j + (j & (-j));
            if (nj <= n) {
                for (int i = 1; i <= m; ++i) {
                    tree[i][nj] += tree[i][j];
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            int ni = i + (i & (-i));
            if (ni <= m) {
                for (int j = 1; j <= n; ++j) {
                    tree[ni][j] += tree[i][j];
                }
            }
        }
    }
    
    // T: O(log(m) * log(n))
    void update(int row, int col, int val) {
        if (m == 0 || n == 0) {
            return;
        }
        int d = val - vals[row][col];
        vals[row][col] = val;
        // How to update a binary indexed tree: 
        // 1. take 2's complement of the original index
        // 2. do bitwise AND with the original index
        // 3. add the AND result back to the original index
        for (int i = row + 1; i <= m; i += (i & (-i))) {
            for (int j = col + 1; j <= n; j += (j & (-j))) {
                tree[i][j] += d;
            }
        }
    }
    
    // T: O(log(m) * log(n))
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m == 0 || n == 0) {
            return 0;
        }
        return prefix_sum(row2 + 1, col2 + 1) - prefix_sum(row2 + 1, col1) - prefix_sum(row1, col2 + 1) + prefix_sum(row1, col1);
    }


};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */