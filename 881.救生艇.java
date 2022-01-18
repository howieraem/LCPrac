import java.util.*;
/*
 * @lc app=leetcode.cn id=881 lang=java
 *
 * [881] 救生艇
 */

// @lc code=start
class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int ans = 0, l = 0, r = people.length - 1;
        // Greedy: carry the lightest and the heaviest each time
        while (l < r) {
            if (people[l] + people[r] <= limit) {
                ++l;
            }   // else just carry people[r]
            --r;
            ++ans;
        }
        // don't forget the middle person if len(people) is odd
        return l == r ? ans + 1 : ans;
    }
}
// @lc code=end

