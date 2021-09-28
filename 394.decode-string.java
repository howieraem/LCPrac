import java.util.*;
/*
 * @lc app=leetcode id=394 lang=java
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
    public String decodeString(String s) {
        Stack<Integer> cntStack = new Stack<>();
        Stack<String> resStack = new Stack<>();
        String res = "";
        int cnt = 0;

        for (char c : s.toCharArray()) {
            if (c == '[') {
                cntStack.push(cnt);
                resStack.push(res);
                cnt = 0;
                res = "";
            } else if (c == ']') {
                int curCnt = cntStack.pop();
                StringBuilder sb = new StringBuilder();
                sb.append(resStack.pop());
                for (int i = 0; i < curCnt; ++i) {
                    sb.append(res);
                }
                res = sb.toString();
            } else if (Character.isDigit(c)) {
                cnt = cnt * 10 + (c - '0');
            } else {
                res += c;
            }
        }
        return res;
    }
}
// @lc code=end

