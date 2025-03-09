/*
 * @lc app=leetcode id=752 lang=java
 *
 * [752] Open the Lock
 */
import java.util.*;

// @lc code=start
class Solution {
    private static final String start = "0000";

    // BFS
    // T: O(k * (d + alpha_size ^ k)), k := len(start), d := len(deadends)
    // S: O(k * (d + alpha_size ^ k))
    public int openLock(String[] deadends, String target) {
        Set<String> vis = new HashSet<>();
        for (String dd : deadends) {
            vis.add(dd);
        }
        if (vis.contains(start) || vis.contains(target)) {
            return -1;
        }

        Queue<String> q = new ArrayDeque<>();
        q.add(start);
        vis.add(start);
        int ans = 0;
        while (!q.isEmpty()) {
            int qs = q.size();
            while (qs-- > 0) {
                String cur = q.poll();
                if (cur.equals(target)) {
                    return ans; 
                }

                for (int i = 0; i < start.length(); ++i) {
                    String up = nextStringUp(cur, i);
                    if (!vis.contains(up)) {
                        q.add(up);
                        vis.add(up);
                    }

                    String down = nextStringDown(cur, i);
                    if (!vis.contains(down)) {
                        q.add(down);
                        vis.add(down);
                    }
                }
            }
            ++ans;
        }

        return -1;
    }

    private String nextStringUp(String s, int i) {
        StringBuilder sb = new StringBuilder(s);
        char c = sb.charAt(i);
        if (c == '9') {
            sb.setCharAt(i, '0');
        } else {
            sb.setCharAt(i, (char)(c + 1));
        }
        return sb.toString();
    }

    private String nextStringDown(String s, int i) {
        StringBuilder sb = new StringBuilder(s);
        char c = sb.charAt(i);
        if (c == '0') {
            sb.setCharAt(i, '9');
        } else {
            sb.setCharAt(i, (char)(c - 1));
        }
        return sb.toString();
    }
}
// @lc code=end

