/*
 * @lc app=leetcode.cn id=402 lang=java
 *
 * [402] 移掉K位数字
 */
import java.util.LinkedList;

// @lc code=start
class Solution {
    public String removeKdigits(String num, int k) {
        LinkedList<Character> dq = new LinkedList<>();
        int n = num.length();
        for (int i = 0; i < n; ++i) {
            // If the current digit is less than the previous digit, 
            // then remove the previous one.
            char digit = num.charAt(i);
            while (k > 0 && !dq.isEmpty() && dq.getLast() > digit) {
                dq.removeLast();
                --k;
            }
            dq.addLast(digit);
        }

        for (int i = 0; i < k; ++i) {
            // If the above process has not removed k digits, 
            // remove the digits at the end.
            dq.removeLast();    
        }

        // Convert to string and remove any leading zeros
        StringBuilder sb = new StringBuilder();
        boolean leadingZero = true;
        while (!dq.isEmpty()) {
            char digit = dq.removeFirst();
            if (leadingZero && digit == '0')  continue;
            leadingZero = false;
            sb.append(digit);
        }
        return sb.length() == 0 ? "0" : sb.toString();
    }
}
// @lc code=end

