/*
 * @lc app=leetcode id=1024 lang=cpp
 *
 * [1024] Video Stitching
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
    // Sort + Greedy, O(N*log(N)), N := the number of clips
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());   // Lexicographic order
        int start = 0, end = 0, idx = 0;
        int ans = 0;
        while (start <= end) {
            ++ans;
            int newStart = end + 1, newEnd = end;
            while (idx < clips.size() && start <= clips[idx][0] && clips[idx][0] <= end) {
                newEnd = max(newEnd, clips[idx][1]);
                if (newEnd >= time) {
                    return ans;
                }
                ++idx;
            }
            start = newStart;
            end = newEnd;
        }
        return -1;
    }
    */

    // Greedy, O(N + T), N := the number of clips, T := time
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> maxn(time);
        for (const auto &clip : clips) {
            if (clip[0] < time) {
                // Get the largest end time for a start time
                maxn[clip[0]] = max(maxn[clip[0]], clip[1]);
            }
        }

        int end = 0, cur_start = 0, ans = 0;
        for (int i = 0; i < time; ++i) {
            end = max(end, maxn[i]);
            if (i == end)  return -1;   // No suitable new clip found before end
            if (i == cur_start) {
                // Use a new clip
                ++ans;
                cur_start = end;
            }
        }
        return ans;
    }
};
// @lc code=end

