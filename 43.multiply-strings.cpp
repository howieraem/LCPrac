/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */
#include <string>

using std::string;

// @lc code=start
class Solution {
public:
    // The following algorithm works with inputs with leading zeros
    // T: O(n1 * n2)
    // S: O(1) (only writes to output string)
    string multiply(string num1, string num2) {
        // if (num1 == "0" || num2 == "0") return "0";

        const int n1 = num1.size(), n2 = num2.size();
        // n1 + n2 is the upper bound of the number of digits of num1 * num2
        string ans(n1 + n2, '0');

        // From least significant bits to most significant bits
        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (ans[i + j + 1] - '0');
                ans[i + j + 1] = sum % 10 + '0';

                // Add the carry, originally: 
                // ans[i + j] = ((sum / 10) + (ans[i + j] - '0')) + '0'
                // "- '0'" and "+ '0'" cancel out.
                ans[i + j] += sum / 10;
            }
        }

        // Skip leading zeros
        // for (int i = 0; i < ans.size(); ++i) {
        //     if (ans[i] != '0')  return ans.substr(i);
        // }
        // return "0";
        auto non_zero_pos = ans.find_first_not_of('0');
        return non_zero_pos != string::npos ? ans.substr(non_zero_pos) : "0";
    }
};
// @lc code=end

