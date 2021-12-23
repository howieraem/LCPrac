/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
#include <climits>
#include <string>

using std::string;

// @lc code=start
#define MAX_TOT INT_MAX / 10
#define MAX_REMAINDER INT_MAX % 10

class Solution {
public:
    int myAtoi(string s) {
        const int n = s.size();
        if (!n)  return 0;  // empty string
        
        int i = 0, sign = 1, tot = 0;
        while (s[i] == ' ' && i++ < n);
        if (i == n)  return 0;  // string with pure spaces

        if (s[i] == '+') { 
            ++i;
        } else if (s[i] == '-') {
            sign = -1;
            ++i;
        }

        while (i < n) {
            int digit = s[i] - '0';
            if (digit < 0 || digit > 9)  break;
            
            // Overflow check
            if (tot > MAX_TOT || (tot == MAX_TOT && digit > MAX_REMAINDER)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            // Append next digit
            tot *= 10;
            tot += digit;
            ++i;
        }
        return tot * sign;
    }
};
// @lc code=end

