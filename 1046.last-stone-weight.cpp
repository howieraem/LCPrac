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
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto &s : stones)  pq.push(s);
        // Above is faster than `priority_queue<int> pq(stones.begin(), stones.end())`

        while (pq.size() > 1) {
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();
            if (s1 > s2)  pq.push(s1 - s2);
        }
        return pq.empty() ? 0 : pq.top();
    }
};
// @lc code=end

