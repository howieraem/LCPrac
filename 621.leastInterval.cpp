/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        int maxFreq = 0, maxNum = 0;
        for (int i = 0; i < tasks.size(); ++i) {
            char c = tasks[i];
            freq[c-'A']++;
            if (freq[c-'A'] > maxFreq) {
                maxFreq = freq[c-'A'];
                maxNum = 1;
            } else if (freq[c-'A'] == maxFreq) {
                maxNum++;
            }
        }
        return max((n+1)*(maxFreq-1)+maxNum, (int) tasks.size());
    }
};
// @lc code=end

