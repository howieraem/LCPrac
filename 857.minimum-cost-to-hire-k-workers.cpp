/*
 * @lc app=leetcode id=857 lang=cpp
 *
 * [857] Minimum Cost to Hire K Workers
 */
#include <algorithm>
#include <cfloat>
#include <queue>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // Rule 1: 
    //      For any two workers in the paid group,
    //      we have wage[i] / wage[j] = quality[i] / quality[j].
    //      So we have wage[i] / quality[i] = wage[j] / quality[j].
    //
    // Rule 2:
    //      To minimize the total wage, we want a small wage/quality ratio.
    //      So we sort all workers with their expected ratio, and pick first k worker.
    //      Redo the process and we can find the minimum total wage. Because workers 
    //      are sorted by ratio of wage/quality. For every ratio, we find the minimum 
    //      possible total quality of K workers. 
    //
    // T: O(n * log(n))
    // S: O(n * log(k))
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<vector<double>> workers;
        for (int i = 0; i < quality.size(); ++i) {
            workers.push_back({(double) (wage[i]) / quality[i], (double) quality[i]});
        }

        sort(workers.begin(), workers.end());   // sort by the ratio (first element of inner vector)
        priority_queue<double> pq;
        double ans = DBL_MAX, qsum = 0;
        for (const auto &worker : workers) {
            qsum += worker[1];
            pq.push(worker[1]);
            if (pq.size() > k) {
                qsum -= pq.top(); pq.pop();
            }
            if (pq.size() == k)  ans = min(ans, qsum * worker[0]);
        }
        return ans;
    }
};
// @lc code=end

