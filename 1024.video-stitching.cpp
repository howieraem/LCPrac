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

    // Greedy, similar to Q45
    // T: O(n + time), n := the number of clips
    // S: O(time)
    int videoStitching(vector<vector<int>>& clips, int time) {
        // Convert to similar input to Q45
        vector<int> can_reach(time);
        for (const auto &clip : clips) {
            if (clip[0] >= 0 && clip[0] < time) {
                // Get the largest end time for a start time
                can_reach[clip[0]] = max(can_reach[clip[0]], clip[1]);
            }
        }

        int ans = 0; 
        int cur_furthest = 0; 
        int cur_pos = 0; 
        int i = 0;
        while (cur_pos < time) {
            // Try skipping the ones already covered
            while (i <= time && i <= cur_pos) {
                cur_furthest = std::max(cur_furthest, can_reach[i++]);
            }

            if (cur_pos == cur_furthest) {
                return -1;
            }

            // Move to next clip
            cur_pos = cur_furthest;
            ++ans;
        }
        return ans;
        /*
        int end = 0, cur_start = 0, ans = 0;
        for (int i = 0; i < time; ++i) {
            end = max(end, can_reach[i]);
            if (i == end)  return -1;   // No suitable new clip found before end
            if (i == cur_start) {
                // Use a new clip
                ++ans;
                cur_start = end;
            }
        }
        return ans;
        */
    }
};
// @lc code=end

