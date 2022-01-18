/*
 * @lc app=leetcode.cn id=420 lang=java
 *
 * [420] 强密码检验器
 */

// @lc code=start
class Solution {
    public int strongPasswordChecker(String password) {
        // 修改次数：替换 < 插入 < 删除

        int missDigit = 1, missLower = 1, missUpper = 1;
        // 统计三种连续型子串的数量：长度模 3 对应为 0，1，2
        int[] modCnt = new int[3];
        int nMod = 0;

        int i = 0, len = password.length();
        while (i < len) {
            char c = password.charAt(i);
            if (Character.isDigit(c))  missDigit = 0;
            if (Character.isLowerCase(c))  missLower = 0;
            if (Character.isUpperCase(c))  missUpper = 0;
            
            int start = i++;
            while (i < len && password.charAt(i) == c)  ++i;
            int sameCharLen = i - start;

            if (sameCharLen >= 3) {
                nMod += sameCharLen / 3;    // 后续修改数等于重复长度除以 3
                ++modCnt[sameCharLen % 3];
            }
        }

        int nMiss = missDigit + missLower + missUpper;  // 下界
        if (len < 6)  return Math.max(6 - len, nMiss);
        if (len <= 20)  return Math.max(nMod, nMiss);

        int diff = len - 20, nRemove = diff;
        if (nRemove < modCnt[0]) {
            // 3n 型子串，部分能通过删除转化成 3n + 2 型子串，每个子串删 1
            return Math.max(nMod - nRemove, nMiss) + diff;
        }
        // 3n 型子串，全部都能通过删除转化成 3n + 2 型子串
        nRemove -= modCnt[0];
        nMod -= modCnt[0];

        if (nRemove < modCnt[1] * 2) {
            // 3n + 1 型子串，部分能通过删除转化成 3n + 2 型子串，每个子串删 2
            return Math.max(nMod - nRemove / 2, nMiss) + diff;
        }
        // 3n + 1 型子串，全部都能通过删除转化成 3n + 2 型子串
        nRemove -= modCnt[1] * 2;
        nMod -= modCnt[1];

        /* 3n + 2型子串
            (1) 删除 len - 20 个字符，使字符串长度降到合法长度
            (2) 根据合法长度的公式，应为 max(nMod, nMiss)
            (3) 由于删除时可以删除连续子串中的字符，减少 nMod
                aaa aaa aa  原需替换 2 次
                aaa aaa a   删除 1 次，仍需替换 2 次
                aaa aaa     删除 2 次，仍需替换 2 次
                aaa aa      删除 3 次，仍需替换 1 次
            即对于 3n + 2 型子串，删除 3 次可抵消替换 1 次
            其他型的子串可以转换成 3n + 2 型
        */
        return Math.max(nMod - nRemove / 3, nMiss) + diff;
    }
}
// @lc code=end

