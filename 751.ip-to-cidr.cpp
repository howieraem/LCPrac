/*
 * @lc app=leetcode id=751 lang=cpp
 *
 * [751] IP to CIDR
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
    vector<string> str_split(const string& s, char delim) {
        std::stringstream ss(s);
        string item;
        vector<string> res;
        while (std::getline(ss, item, delim)) {
            res.push_back(std::move(item));
        }
        return res;
    }

    string to_CIDR(long x, long cnt) {
        // Compute 4 parts of the ip from right to left
        string a, b, c, d;
        d = std::to_string(x & 255);
        x >>= 8;
        c = std::to_string(x & 255);
        x >>= 8;
        b = std::to_string(x & 255);
        x >>= 8;
        a = std::to_string(x & 255);

        string res = a + "." + b + "." + c + "." + d + "/";

        int len = 0;
        while (cnt > 0) {
            cnt >>= 1;
            ++len;
        }
        int prefix_len = 32 - (len - 1);
        return res.append(std::to_string(prefix_len));
    }

public:
    // T: O(n + len(ip))
    // S: O(len(ip))
    vector<string> ipToCIDR(string ip, int n) {
        long x = 0;
        vector<string> parts = str_split(ip, '.');
        for (const auto& p : parts) {
            x <<= 8; // x *= 256
            x += std::stol(p);
        }

        vector<string> res;
        while (n > 0) {
            // How many more ips we can represent with CIDR if 
            // we don't change the current start ip
            long cnt = x & -x;
            if (cnt == 0) {
                // "0.0.0.0"
                int nc = n, len = 0;
                while (nc > 1) {
                    nc >>= 1;
                    ++len;
                }
                cnt = 1 << len;
            }

            while (cnt > n) {
                cnt >>= 1;
            }
            res.push_back(std::move(to_CIDR(x, cnt)));
            n -= (int)cnt;
            x += cnt;
        }
        return res;
    }
};
// @lc code=end

