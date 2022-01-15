/*
 * @lc app=leetcode id=1560 lang=cpp
 *
 * [1560] Most Visited Sector in  a Circular Track
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // Since the disk only spin in one direction, 
    // the intermediate stops do not matter.
    //               start ---- n
    // 1 ---------------------- n
    // 1 ---------------------- n
    // 1 --- end
    // Case 1: start <= end
    //     --->> return the range [start, end].
    // Case 2: start > end
    //     --->> return the range [1, end] + range [start, n]
    // T: O(n)
    // S: O(1)
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> res;
        if (rounds.front() <= rounds.back()) {
            for (int i = rounds.front(); i <= rounds.back(); ++i) {
                res.push_back(i);
            }
        } else {
            for (int i = 1; i <= rounds.back(); ++i) {
                res.push_back(i);
            }
            for (int i = rounds.front(); i <= n; ++i) {
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

