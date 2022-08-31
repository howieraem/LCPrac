/*
 * @lc app=leetcode id=1996 lang=cpp
 *
 * [1996] The Number of Weak Characters in the Game
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n))
    // S: O(log(n)) for std::sort()
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // Sort by attack ASC and then defense DESC
        std::sort(properties.begin(), properties.end(), [] (const vector<int>& a, const vector<int>& b) { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; } );

        // After sorting, any character in properties must be weaker or on par with 
        // its next character in terms of attack, so no need to compare attack in 
        // the loop below.
        // Iterate backwards to avoid using a stack to compare defense.
        int max_defense = INT_MIN, ans = 0;
        for (int i = properties.size() - 1; i >= 0; --i) {
            ans += (properties[i][1] < max_defense);
            max_defense = std::max(max_defense, properties[i][1]);
        }
        return ans;
    }
};
// @lc code=end

