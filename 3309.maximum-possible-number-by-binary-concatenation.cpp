#include <bits/stdc++.h>

using std::string;
using std::vector;

class Solution {
    string convert_to_bin_str(int num) {
        if (num == 0) {
            return "0";
        }
        string res;
        while (num != 0) {
            res.push_back((num & 1) == 0 ? '0' : '1');
            num >>= 1;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }

public:
    // T: O(n * log(n))
    // S: O(n)
    int maxGoodNumber(vector<int>& nums) {
        vector<string> bin_strs(nums.size());
        size_t final_res_sz = 0;
        for (int i = 0; i < nums.size(); ++i) {
            bin_strs[i] = convert_to_bin_str(nums[i]);
            final_res_sz += bin_strs[i].size();
        }

        std::sort(bin_strs.begin(), bin_strs.end(), [](const string& a, const string& b) {
                return (b + a) < (a + b);  // desc
        });

        string res;
        res.reserve(final_res_sz);
        for (auto& s : bin_strs) {
            res.append(std::move(s));
        }
        return std::stoi(res, nullptr, 2);
    }
};