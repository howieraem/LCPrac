/*
 * @lc app=leetcode.cn id=1723 lang=java
 *
 * [1723] 完成所有工作的最短时间
 */

// @lc code=start
class Solution {
    private int[] jobs;
    private int n, k;
    private int ans = Integer.MAX_VALUE;

    public int minimumTimeRequired(int[] jobs, int k) {
        this.jobs = jobs;
        this.n = jobs.length;
        this.k = k;
        dfs(0, 0, new int[k], 0);
        return this.ans;
    }

    /**
     * 回溯法带剪枝
     * 
     * @param jobIdx 当前处理到哪个job
     * @param busy 当前多少工人已被分配
     * @param assign 工人的分配情况，例如 sum[0] 表示 0 号工人的工作量为 x
     * @param max 当前的最大工作时间
     */
    private void dfs(int jobIdx, int busy, int[] assign, int max) {
        if (max >= ans)  return;    // 剪枝
        if (jobIdx == n) {
            ans = max;
            return;
        }

        if (busy < k) {
            // 剪枝：优先分配给空闲的工人
            assign[busy] = jobs[jobIdx];
            dfs(jobIdx + 1, busy + 1, assign, Math.max(max, assign[busy]));
            assign[busy] = 0;   // 回溯
        }
        for (int i = 0; i < busy; ++i) {
            assign[i] += jobs[jobIdx];
            dfs(jobIdx + 1, busy, assign, Math.max(max, assign[i]));
            assign[i] -= jobs[jobIdx];  // 回溯
        }
    }
}
// @lc code=end

