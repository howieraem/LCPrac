/*
 * @lc app=leetcode id=1152 lang=cpp
 *
 * [1152] Analyze User Website Visit Pattern
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
public:
    // T: O(n ^ 3)
    // S: O(n ^ 3)
    std::vector<std::string> mostVisitedPattern(
            std::vector<std::string>& username, std::vector<int>& timestamp, std::vector<std::string>& website) {
        // Preprocess data: user -> timestamp -> website
        std::unordered_map<std::string, std::map<int, std::string>> user_data;
        for (int i = 0; i < username.size(); ++i) {
            user_data[username[i]][timestamp[i]] = website[i];
        }

        // For each user, get all possible unique 3-website sequences,
        // then update the count of each sequence across users
        std::unordered_map<std::string, int> seq_cnts;
        for (const auto &p : user_data) {
            std::unordered_set<std::string> seqs;
            for (auto it1 = p.second.begin(); it1 != p.second.end(); ++it1) {
                for (auto it2 = std::next(it1); it2 != p.second.end(); ++it2) {
                    for (auto it3 = std::next(it2); it3 != p.second.end(); ++it3) {
                        seqs.insert(it1->second + "$" + it2->second + "#" + it3->second);
                    }
                }
            }

            for (const auto &s : seqs) {
                ++seq_cnts[s];
            }
        }

        // Find the most common pattern
        int max_cnt = 0;
        std::string res;
        for (const auto &p : seq_cnts) {
            // If there is more than one solution, return the lexicographically smallest one
            if (p.second >= max_cnt) {
                res = res.empty() || p.second > max_cnt ? p.first : std::min(p.first, res);
                max_cnt = p.second;
            }
        }

        // Postprocess: construct vector<string> from "{website1}${website2}#{website3}"
        auto sep1 = res.find("$"), sep2 = res.find("#");
        return {
            res.substr(0, sep1),
            res.substr(sep1 + 1, sep2 - sep1 - 1),
            res.substr(sep2 + 1)
        };
    }
};
// @lc code=end
