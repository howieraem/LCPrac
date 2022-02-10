/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */
#include <cstdlib>  // for rand()
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    int n;

    // note: depending on the input weight, may need long long type
    vector<int> preSum;

public:
    // T: O(n)
    // S: O(n)
    Solution(vector<int>& w) {
        n = w.size();
        preSum = vector<int>(n, 0);
        preSum[0] = w[0];
        for (int i = 1; i < n; ++i) {
            preSum[i] = preSum[i - 1] + w[i];
        }
    }

    // Do binary search on the prefix sum array of weights.
    // Example:    
    //     w = [1, 3]
    //     i = [0, 1]
    //     prefix sum = [1, 4]
    //   The prefix sums form the following intervals:
    //     {[0, 1), [1, 4)}
    //   We can then generate a random number in [0, 4) and see which interval it falls into. 
    //   The answer to the question is equivalent to the index of: 
    //     - the closest prefix sum greater than this number
    //     - the next prefix sum if this number equals a prefix sum
    //   Since weights are positive, their prefix sums must be sorted. Binary search is the 
    //   most efficient.
    //
    // T: O(log(n))
    // S: O(1)
    int pickIndex() {
        int target = rand() % preSum.back(), l = 0, r = n - 1, m;
        while (l < r) {
            m = l + ((r - l) >> 1);
            if (preSum[m] > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

