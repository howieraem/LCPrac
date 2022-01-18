/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */
#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (!numerator)  return "0";
        string res;
        if ((numerator < 0) ^ (denominator < 0)) {
            res = "-";  // negative
        }

        long n = abs((long) numerator), d = abs((long) denominator);
        res.append(to_string(n / d));     // the integer part
        long r = n % d;
        if (!r)  return res;

        res.push_back('.');
        unordered_map<long, int> mp;
        while (r != 0) {
            if (mp.find(r) != mp.end()) {
                // recursion found
                res.insert(mp[r], "("); // res.insert(mp[r], 1, '(');
                res.push_back(')');
                return res;
            }

            mp[r] = res.size();
            r *= 10;
            res.append(to_string(r / d));
            r %= d;
        }
        return res;
    }
};
// @lc code=end

