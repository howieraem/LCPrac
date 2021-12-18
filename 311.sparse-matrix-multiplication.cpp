/*
 * @lc app=leetcode id=311 lang=cpp
 *
 * [311] Sparse Matrix Multiplication
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
typedef tuple<int, int, int> triple;    // cannot do triple[i] but std::get<i>(triple)

class Solution {
public:
    /*
    // S: O(m * n)
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        const int m = mat1.size(), K = mat1[0].size(), n = mat2[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        // Worst case T: O(m * K * n), when all entries are non-zero.
        // No auxiliary unordered_map used. In reality, however,
        // the res matrix returned may not be in dense form but
        // in the form of nested linked-list, which needs hash
        // maps to pre-compress the input matrices.
        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < K; ++k) {
                if (mat1[i][k]) {
                    for (int j = 0; j < n; ++j) {
                        if (mat2[k][j]) {
                            res[i][j] += mat1[i][k] * mat2[k][j];
                        }
                    }
                }
            }
        }
        return res;
    }
    */

    // A more realistic solution.
    // See https://leetcode.com/problems/sparse-matrix-multiplication/discuss/419538/ for more discussion.
    // S: O(M_nz + N_nz), M_nz := the number of non-zero entries in mat1, N_nz := the number of non-zero entries in mat2
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        const int m = mat1.size(), K = mat1[0].size(), n = mat2[0].size();
        vector<triple> c1 = compress(mat1), c2 = compress(mat2);
        vector<triple> c = sparseMul(c1, c2);
        return toDense(c, m, n);
    }

private:
    static vector<triple> compress(vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size();

        vector<triple> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) {
                    res.emplace_back(i, j, mat[i][j]);
                }
            }
        }
        return res;
    }

    static vector<triple> sparseMul(vector<triple>& c1, vector<triple>& c2) {
        unordered_map<int, vector<pair<int, int>>> mp;
        for (const auto &item : c1) {
            mp[get<1>(item)].emplace_back(get<0>(item), get<2>(item));
        }

        unordered_map<int, unordered_map<int, int>> resMp;
        for (const auto &item : c2) {
            if (mp.find(get<0>(item)) != mp.end()) {
                for (const auto &p : mp[get<0>(item)]) {
                    unordered_map<int, int> *r1 = &resMp[p.first];
                    (*r1)[get<1>(item)] += get<2>(item) * p.second;
                }
            }
        }

        vector<triple> res;
        for (const auto &e1 : resMp) {
            for (const auto &e2 : e1.second) {
                res.emplace_back(e1.first, e2.first, e2.second);
            }
        }
        return res;
    }

    static vector<vector<int>> toDense(vector<triple>& compressed, int m, int n) {
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (const auto &item : compressed) {
            res[get<0>(item)][get<1>(item)] = get<2>(item);
        }
        return res;
    }
};
// @lc code=end

