/*
 * @lc app=leetcode.cn id=13 lang=java
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
    public int romanToInt(String s) {
        int sum = 0;
        int preNum = getValue(s.charAt(0));
        for (int i = 1; i < s.length(); ++i) {
            int num = getValue(s.charAt(i));
            if (preNum < num) {
                // preNum is 'I', Num is 'V' or 'X'; etc.
                sum -= preNum;
            } else {
                // normally, larger digits will be on the left
                sum += preNum;
            }
            preNum = num;
        }
        sum += preNum;  // don't forget the last one
        return sum;
    }
    
    private int getValue(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    /*
    original solution:

    public int romanToInt(String s) {
        char[] chars = s.toCharArray();
        int res = 0;
        int l = chars.length;
        boolean skip = false;
        for (int i=0; i<l; ++i) {
            if (skip) {
                skip = false; 
                continue;
            }
            char c = chars[i];
            switch (c) {
                case 'M':
                    res += 1000; break;
                case 'D':
                    res += 500; break;
                case 'C':
                    if (i<l-1) {
                        char nc = chars[i+1];
                        if (nc == 'M') {
                            res += 900; skip=true; break;
                        } else if (nc == 'D') {
                            res += 400; skip=true; break;
                        }
                    }
                    res += 100; break;
                case 'L':
                    res += 50; break;
                case 'X':
                    if (i<l-1) {
                        char nc = chars[i+1];
                        if (nc == 'C') {
                            res += 90; skip=true; break;
                        } else if (nc == 'L') {
                            res += 40; skip=true; break;
                        }
                    }
                    res += 10; break;
                case 'V':
                    res += 5; break;
                case 'I':
                    if (i<l-1) {
                        char nc = chars[i+1];
                        if (nc == 'X') {
                            res += 9; skip=true; break;
                        } else if (nc == 'V') {
                            res += 4; skip=true; break;
                        }
                    }
                    res += 1; break;
            }
        }
        return res;
    }
    */
}

// @lc code=end

// class Test {
//     public static void main(String[] args) {
//         Solution s = new Solution();
//         System.out.println(s.romanToInt("LVIII"));
//     }
// }
