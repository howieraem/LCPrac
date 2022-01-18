/*
 * @lc app=leetcode id=468 lang=java
 *
 * [468] Validate IP Address
 */

// @lc code=start
class Solution {
    public String validIPAddress(String IP) {
        if (IP.isBlank())  return "Neither";

        String[] v4 = IP.split("\\.", -1);
        // Whether the string has three '.'
        if (IP.chars().filter(c -> c == '.').count() == 3) {
            for (String s : v4) {
                if (!validV4Seg(s))  return "Neither";
            }
            return "IPv4";
        }

        String[] v6 = IP.split("\\:", -1);
        // Whether the string has three ':'
        if (IP.chars().filter(c -> c == ':').count() == 7) {
            for (String s : v6) {
                if (!validV6Seg(s))  return "Neither";
            }
            return "IPv6";
        }
        return "Neither";
    }

    private static boolean validV4Seg(String s) {
        try {
            int i = Integer.parseInt(s);
            // `String.valueOf(Integer.valueOf(s)).equals(s)` checks leading zeros 
            // and cases like "1e1"
            return String.valueOf(Integer.valueOf(s)).equals(s) && i >= 0 && i <= 255; 
        } catch (NumberFormatException e) { 
            return false; 
        } 
    }

    private static boolean validV6Seg(String s) {
        if (s.length() > 4)  return false;
        try {
            return Integer.parseInt(s, 16) >= 0 && s.charAt(0) != '-';
        } catch (NumberFormatException e) {
            return false;
        }
    }
}
// @lc code=end

