/*
 * @lc app=leetcode id=1507 lang=cpp
 *
 * [1507] Reformat Date
 */
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> months = {
            {"Jan", "01"},
            {"Feb", "02"},
            {"Mar", "03"},
            {"Apr", "04"},
            {"May", "05"},
            {"Jun", "06"},
            {"Jul", "07"},
            {"Aug", "08"},
            {"Sep", "09"},
            {"Oct", "10"},
            {"Nov", "11"},
            {"Dec", "12"}
        };

        return date.length() == 13 ? 
            date.substr(9,4) + '-' + months[date.substr(5,3)] + '-' + date.substr(0,2) : 
            date.substr(8,4) + '-' + months[date.substr(4,3)] + '-' + '0' + date.substr(0,1);
    }
};
// @lc code=end

