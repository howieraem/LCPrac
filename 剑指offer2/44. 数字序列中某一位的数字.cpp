// See https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof
// for more explanations.
class Solution {
public:
    int findNthDigit(int n) {
        int digit = 1, start = 1;
        long cnt = 9;
        while (n > cnt) {
            n -= cnt;
            start *= 10;
            ++digit;
            cnt = (long) 9 * start * digit;
        }
        const long num = start + (n - 1) / digit;
        return to_string(num)[(n - 1) % digit] - '0';
    }
};