/*
 * @lc app=leetcode.cn id=405 lang=java
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution {
    private static final char[] HEX = {
        '0', '1', '2', '3', '4', '5', '6', '7', 
        '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    public String toHex(int num) {
        if (num == 0)  return "0";
        StringBuilder ans = new StringBuilder();

        // 位移运算并不能保证最终 num == 0，需要使用32位int保证（对应16进制小于等于8位）
        while (num != 0 && ans.length() < 8) {
            // num & 0xf (0b1111) returns the least significant 4 bits
            ans.insert(0, HEX[num & 0xf]);
            num >>= 4;  // 算数位移，其中正数右移左边补 0，负数右移左边补 1
        }
        return ans.toString();
    }
}
// @lc code=end

