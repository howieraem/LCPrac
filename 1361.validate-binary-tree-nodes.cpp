/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    bool validateBinaryTreeNodes(int n, vector<int>& lCh, vector<int>& rCh) {
        vector<int> childrenCnt(n), roots(n, -1);
        for (int i = 0; i < n; ++i) {
            if (!processLink(childrenCnt, roots, i, lCh[i]) || !processLink(childrenCnt, roots, i, rCh[i])) {
                return false;
            }
        }
        return count_if(begin(childrenCnt), end(childrenCnt), [](int i) { return i == 0; }) == 1 &&
            count_if(begin(roots), end(roots), [](int i) { return i == -1; }) == 1;
    }

private:
    static int find(vector<int> &roots, int i) {
        return roots[i] < 0 ? i : roots[i] = find(roots, roots[i]);
    }

    static bool processLink(vector<int> &childrenCnt, vector<int> &roots, int parent, int child) {
        if (child == -1)  return true;
        auto p = find(roots, parent), c = find(roots, child);
        if (p != c) {
            roots[c] = p;
        }
        return ++childrenCnt[child] < 2;    // binary tree
    }
};
// @lc code=end

