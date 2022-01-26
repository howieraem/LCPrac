/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
#define START 0
#define END 1
#define PROFIT 2

typedef tuple<int, int, int> job;

class Solution {
public:
    // T: O(n * log(n))
    // S: O(n)
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        const int n = startTime.size();
        vector<job> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end(), [](const job &a, const job &b) { 
            return get<END>(a) < get<END>(b);   // Sort by end time ascendingly
        });
        
        vector<int> dp(n, 0);   // dp[i] represents maximum profit for jobs[:i]
        dp[0] = get<PROFIT>(jobs[0]);   // Base case: the profit of the job ending first
        for (int i = 1; i < n; ++i) {
            // Base case: select just the current job or the previous selected job(s)
            dp[i] = max(dp[i - 1], get<PROFIT>(jobs[i]));

            // Try including more jobs
            int j = i - 1;
            while (j >= 0 && get<END>(jobs[j]) > get<START>(jobs[i]))  --j;
            // Since jobs are sorted by end time, find the closest previous job 
            // without overlapping the current job, and decide whether to 
            // add profits from these ealier jobs or not
            if (j >= 0)  dp[i] = max(dp[i], get<PROFIT>(jobs[i]) + dp[j]);
        }
        return dp.back();
    }
};
// @lc code=end

