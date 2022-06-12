/*
 * @lc app=leetcode id=158 lang=cpp
 *
 * [158] Read N Characters Given read4 II - Call Multiple Times
 */

int read4(char *buf4);

// @lc code=start
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
    char buf4[4];   // passed to read4()
    int i = 0;  // index of buf4
    int chars_remain = 0;   // unread chars in buf4

public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        if (!chars_remain) {
            chars_remain = read4(buf4);
            i = 0;
        }

        int p = 0;
        while (p < n && chars_remain) {
            buf[p++] = buf4[i++];
            --chars_remain;

            if (!chars_remain) {
                chars_remain = read4(buf4);
                i = 0;
            }
        }
        return p;
    }
};
// @lc code=end

