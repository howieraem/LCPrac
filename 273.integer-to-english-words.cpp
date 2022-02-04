/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */
#include <algorithm>  // std::find_if
#include <cctype>     // std::isspace
#include <string>     
#include <vector>     // std::erase

using namespace std;

// @lc code=start
class Solution {
    // Note that element at index 0 in the following is just a placeholder,
    // so that when indexing the word there is no need to subtract 1.
    const vector<string> LESS_THAN_20 {
        "", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", 
        "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", 
        "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", 
        "Seventeen ", "Eighteen ", "Nineteen "};
    const vector<string> TENS {
        "", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", 
        "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    const vector<string> THOUSANDS {
        "", "Thousand ", "Million ", "Billion "};

    // For number less than 1000
    string helper(int num) {
        if (!num)  return "";
        else if (num < 20)  return LESS_THAN_20[num];
        else if (num < 100)  return TENS[num / 10] + helper(num % 10);
        return LESS_THAN_20[num / 100] + "Hundred " + helper(num % 100);
    }

public:
    // T: O(log(num))
    // S: O(log(num)) (recursion stack)
    string numberToWords(int num) {
        if (!num)  return "Zero";
        int i = 0;
        string res;

        while (num) {
            if (num % 1000) {
                res = helper(num % 1000) + THOUSANDS[i] + res;
            }
            num /= 1000;
            ++i;
        }

        res.pop_back();     // remove trailing space
        return res;
    }
};
// @lc code=end

