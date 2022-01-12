/*
 * @lc app=leetcode id=592 lang=java
 *
 * [592] Fraction Addition and Subtraction
 */

// @lc code=start
class Solution {
    // T: O(n), n := len(expression)
    // S: O(1)
    public String fractionAddition(String expression) {
        int numerator = 0, denominator = 1, i = 0;
        char[] s = expression.toCharArray();
        while (i < s.length) {
            int curNumerator = 0, curDenominator = 0;
            boolean neg = false;
            if (s[i] == '-') {
                neg = true;
                ++i;
            } else if (s[i] == '+') {
                ++i;
            }

            while (Character.isDigit(s[i])) {
                curNumerator = curNumerator * 10 + s[i++] - '0';
            }
            if (neg)  curNumerator *= -1;
            ++i;

            while (i < s.length && Character.isDigit(s[i])) {
                curDenominator = curDenominator * 10 + s[i++] - '0';
            }
 
            // reduction of fractions to a common denominator
            numerator = numerator * curDenominator + curNumerator * denominator;
            denominator *= curDenominator;            
        }
        int gcd = Math.abs(calcGCD(numerator, denominator));
        numerator /= gcd;
        denominator /= gcd;
        return numerator + "/" + denominator;
    }

    private static final int calcGCD(int a, int b) {
        return a == 0 ? b : calcGCD(b % a, a);
    }
}
// @lc code=end

