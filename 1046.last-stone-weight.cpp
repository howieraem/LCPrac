/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // Heap + Simulation
    // T: O(n * log(n))
    // S: O(n)
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (const auto& s : stones) {
            pq.push(s);
        }
        // Above is faster than `priority_queue<int> pq(stones.begin(), stones.end())`

        while (pq.size() >= 2) {
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();
            int diff = s1 - s2;
            if (diff > 0) {
                pq.push(std::move(diff));
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
// @lc code=end

