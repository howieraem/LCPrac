import java.util.Stack;

/*
 * @lc app=leetcode.cn id=388 lang=java
 *
 * [388] 文件的最长绝对路径
 */

// @lc code=start
class Solution {
    public int lengthLongestPath(String input) {
        Stack<Integer> stack = new Stack<>();
        stack.push(0);
        int ans = 0;

        String[] names = input.split("\n");
        for (String name : names) {
            // level 代表当前字符串的首字母索引也是 \t 的个数
            // 字符串前面可能会有多个 \t,故使用 lastIndexOf 找出最后一个 \t 位置即可
            int level = name.lastIndexOf("\t") + 1;
            while (level + 1 < stack.size()) {
                // 跳过已访问的同级目录或文件
                stack.pop();
            }

            // len 为上一层目录长度 + 文件名 + （level - 1）个 "/"
            int len = stack.peek() + (name.length() - level + 1);
            stack.push(len);
            if (name.contains(".")) { 
                ans = Math.max(ans, len - 1); 
            }
        }
        return ans;
    }
}
// @lc code=end

