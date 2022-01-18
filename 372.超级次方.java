import java.util.Stack;
/*
 * @lc app=leetcode.cn id=372 lang=java
 *
 * [372] 超级次方
 */

// @lc code=start
class Solution {
    private static final int BASE = 1337;

    public int superPow(int a, int[] b) {
        Stack<Integer> bs = new Stack<>();
        for (int num : b) {
            bs.add(num);
        }
        return superPow(a, bs);
    }

    private int superPow(int a, Stack<Integer> b) {
        // a^[x, y, z] = a^z * a^[x, y, 0] = a^z * (a^[x,y])^10
        if (b.isEmpty())  return 1;
        int last = b.pop();
        int part1 = fastPowMod(a, last);
        int part2 = fastPowMod(superPow(a, b), 10);
        return (part1 * part2) % BASE;
    }

    /*
    private int powMod(int a, int k) {
        // (a*b) % m = (a % m)(b % m) % m
        a %= BASE;  // less than Integer.MAX_VALUE
        int res = 1;
        while (k > 0) {
            res *= a;
            res %= BASE;
            --k;
        }
        return res;
    }
    */

    private int fastPowMod(int a, int k) {
        // 1. (a*b) % m = (a % m)(b % m) % m;
        // 2. a^b = a*a^(b-1) if b is odd number else (a^(b/2))^2  
        if (k == 0)  return 1;
        a %= BASE;  // less than Integer.MAX_VALUE
        if ((k & 1) == 1) {
            return (a * fastPowMod(a, k - 1)) % BASE;
        }
        int sub = fastPowMod(a, k / 2);
        return (sub * sub) % BASE;
    }
}
// @lc code=end

