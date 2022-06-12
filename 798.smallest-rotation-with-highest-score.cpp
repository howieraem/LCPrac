/*
 * @lc app=leetcode id=798 lang=cpp
 *
 * [798] Smallest Rotation with Highest Score
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // Idea: find how the score changes when k increments
    // T: O(n)
    // S: O(n)
    int bestRotation(vector<int>& nums) {
        const int N = nums.size(); // 0 <= k < N

        // vector<int> score(N, 0);
        // Whether to find the actual score[0] doesn't affect the result,
        // and thus we can just accumulate the changes to find the max.
        vector<int> change(N, 0);

        for (int i = 0; i < N; ++i) {
            /*
            Explanation: 
                (i - nums[i] + N) % N is the value of k making nums[i]'s 
                index just equal to nums[i]. Then if k is bigger, i.e. 
                when k = (i - nums[i] + 1 + N) % N, we start to lose a
                point, so the change -= 1. Record the value of k for 
                all nums[i] where we will lose points.

            Proof:
                After rotating, new_i = (i - k + N) % N.
                
                If k <= i, then new_i = i - k.
                    For new_i >= nums[i], i - k >= nums[i].
                    Thus, k <= i - nums[i]

                If k > i, then new_i = i - k + N.
                    For new_i >= nums[i], i - k + N >= nums[i]
                    Thus, k <= i - nums[i] + N

                Combining both cases, k <= (i - nums[i] + N) % N
            */
            --change[(i - nums[i] + 1 + N) % N];
        }

        int ans = 0;
        for (int i = 1; i < N; ++i) {
            // Add 1 because for every rotation, we shift nums[0] to nums[N - 1].
            // Since nums[N - 1] <= N - 1 is always true, we get a point.
            // score[i] = score[i - 1] + change[i] + 1;
            change[i] += change[i - 1] + 1;
    
            // ans := argmax(`score`) = argmax(prefix sum of `change`)
            // ans = score[i] > score[ans] ? i : ans;
            ans = change[i] > change[ans] ? i : ans;
        }
        return ans;
    }
};
// @lc code=end

