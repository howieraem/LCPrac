/*
 * @lc app=leetcode id=1899 lang=cpp
 *
 * [1899] Merge Triplets to Form Target Triplet
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * m). m := the number of dimensions which is 3 in this problem
    // S: O(m)
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool isFound[3] {};

        // Greedy: Because of the operation rule, for all the triplets involved, 
        // their dimension values must be no greater than the corresponding 
        // dimension values in target. We can safely discard triplets that 
        // don't satisfy this rule. 
        for (const auto& tri : triplets) {
            if (tri[0] <= target[0] && tri[1] <= target[1] && tri[2] <= target[2]) {
                // The current triplet satisfies the rule above. Now check if it is 
                // a candidate involved. Each dimension of the candidate triplets 
                // involved must contain the value of the corresponding dimension 
                // of the target triplet.
                isFound[0] |= tri[0] == target[0];
                isFound[1] |= tri[1] == target[1];
                isFound[2] |= tri[2] == target[2];
            }
        }

        return isFound[0] && isFound[1] && isFound[2];
    }
};
// @lc code=end

