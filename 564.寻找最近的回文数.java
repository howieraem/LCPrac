/*
 * @lc app=leetcode.cn id=564 lang=java
 *
 * [564] 寻找最近的回文数
 */

// @lc code=start
class Solution {
    public String nearestPalindromic(String n) {
        // Make an initial palindrome from the string, which
        // might not be the closest or the smallest
        char[] a = n.toCharArray();
        for (int l = 0, r = n.length() - 1; l < r; ++l, --r) {
            a[r] = a[l];
        }
        String curS = String.valueOf(a);

        // Find the next smaller palindrome and the next greater palindrome 
        // for the initial palindrome
        String preS = nearest(curS, false);
        String nxtS = nearest(curS, true);

        long num = Long.parseLong(n), cur = Long.parseLong(curS), 
                pre = Long.parseLong(preS), nxt = Long.parseLong(nxtS);

        // Compare the difference
        if (num == cur) {
            // n is already a palindrome
            return Math.abs(num - pre) <= Math.abs(num - nxt) ? preS : nxtS;
        } else if (num < cur) {
            return Math.abs(num - cur) < Math.abs(num - pre) ? curS : preS;
        } else {
            return Math.abs(num - cur) <= Math.abs(num - nxt) ? curS : nxtS;
        }
    }

    private String nearest(String n, boolean isGreater) {
        int len = n.length();
        int r = (len >> 1), l = len - r;
        
        long leftHalf = Long.parseLong(n.substring(0, l));
        // Try adding or subtracting 1 to the number representing the 
        // left half of the initial palindrome.
        if (isGreater)  ++leftHalf;
        else  --leftHalf;
        if (leftHalf == 0) {
            // Special cases:
            // r == 0: "1"
            // r != 0: "11"
            return r == 0 ? "0" : "9";
        }

        // Build a new palindrome based on the left half
        StringBuilder sbLeftHalf = new StringBuilder(Long.toString(leftHalf));
        StringBuilder sbRightHalf = new StringBuilder(sbLeftHalf).reverse();

        // Deal with boundary cases for odd/even string length
        if (r > sbLeftHalf.length())  sbRightHalf.append('9');
        return sbLeftHalf.append(sbRightHalf.substring(sbRightHalf.length() - r)).toString();
    }
}
// @lc code=end

