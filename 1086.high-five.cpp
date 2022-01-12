/*
 * @lc app=leetcode id=1086 lang=cpp
 *
 * [1086] High Five
 */
#include <map>
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n))
    // S: O(n)
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>, greater<int>>> mp;

        // One priority queue (maximum size 5) for each ID
        for (const auto &item : items) {
            int id = item[0], score = item[1];
            priority_queue<int, vector<int>, greater<int>> *pq = &mp[id];
            pq->push(score);
            if (pq->size() > 5) {
                pq->pop();
            }
        }

        // Calculate average for each ID
        vector<vector<int>> res(mp.size());
        int i = 0;
        for (auto &p : mp) {
            int sum = 0, qs = p.second.size();
            for (int j = 0; j < qs; ++j) {
                sum += p.second.top(); p.second.pop();
            }
            res[i++] = {p.first, sum / qs};
        }
        return res;
    }
};
// @lc code=end

