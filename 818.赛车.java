import java.util.*;
/*
 * @lc app=leetcode.cn id=818 lang=java
 *
 * [818] 赛车
 */

// @lc code=start
class State {
    int pos, speed;

    public State(int _pos, int _speed) {
        pos = _pos;
        speed = _speed;
    }

    @Override
    public boolean equals(Object other) {
        if (!(other instanceof State))  return false;
        State p = (State) other;
        return pos == p.pos && speed == p.speed;
    }

    @Override
    public int hashCode() {
        return Objects.hash(pos, speed);
    }
}

class Solution {
    // private int[] memo;

    // public int racecar(int target) {
    //     memo = new int[target + 1];
    //     return dp(target);
    // }

    // private static double log2(int n) {
    //     return Math.log(n) / Math.log(2);
    // }

    // private int dp(int target) {
    //     if (memo[target] > 0)  return memo[target];
    //     int n = (int) Math.ceil(log2(target + 1));
    //     if (target + 1 == (1 << n)) {
    //         memo[target] = n;
    //         return n;
    //     }
    //     memo[target] = n + 1 + dp((1 << n) - 1 - target);
    //     for (int i = 0; i < n - 1; ++i) {
    //         int cur = (1 << (n - 1)) - (1 << i);
    //         memo[target] = Math.min(memo[target], n + i + 1 + dp(target - cur));
    //     }
    //     return memo[target];
    // }

    public int racecar(int target) {
        Queue<State> q = new ArrayDeque<>();
        q.offer(new State(0, 1));
        Set<State> seen = new HashSet<>();
        seen.add(new State(0, 1));
        seen.add(new State(0, -1));     // prevent going back at step 1

        int ans = 0;
        while (!q.isEmpty()) {
            int qs = q.size();
            while (qs-- > 0) {
                State p = q.poll();
                int pos = p.pos, speed = p.speed;

                // A
                int pos1 = pos + speed;
                int speed1 = (speed << 1);
                if (pos1 == target)  return ans + 1;
                if (pos1 > 0 && pos1 < (target << 1)) {
                    // prune
                    q.offer(new State(pos1, speed1));
                }

                // R
                int speed2 = speed > 0 ? -1 : 1;
                State p2 = new State(pos, speed2);
                if (!seen.contains(p2)) {
                    q.offer(p2);
                    seen.add(p2);
                }
            }
            ++ans;
        }
        return -1;
    }
}
// @lc code=end

