/** 
 * https://leetcode.com/discuss/interview-question/989768
 * 
 * A Company parses logs of online store user transactions/activity to flag fraudulent activity. 
 * The log file is represented as an Array of arrays. The arrays consist of the following data:
 * [ <# of transactions>]
 * For example:
 * [345366 89921 45]
 * Note: the data is space delimited
 * 
 * So, the log data would look like:
 * [
 *   [345366 89921 45],
 *   [029323 38239 23]
 *   ...
 * ]
 * Write a function to parse the log data to find distinct users that meet or cross a certain threshold.
 * The function will take in 2 inputs:
 * - logData: Log data in form an array of arrays
 * - threshold: threshold as an integer
 * 
 * Output: It should be an array of userids that are sorted. 
 * If same userid appears in the transaction as userid1 and userid2, it should count as one occurrence, not two.
 */ 
#include <bits/stdc++.h>

// T: O(n)
// S: O(n)
std::vector<std::string> get_fraud_id(std::vector<std::string>& uid, int thres) {
    std::unordered_map<std::string, int> mp;
    std::vector<std::string> tmp;
    tmp.reserve(3);
    std::string w;
    for (int i = 0; i < uid.size(); ++i) {
        std::stringstream ss(uid[i]);
        while (ss >> w) {
            tmp.push_back(w);
        }
        ++mp[tmp[0]];
        if (tmp[0] != tmp[1]) {
            ++mp[tmp[1]];
        }
        tmp.clear();
    }

    std::vector<std::string> res;
    for (const auto& p : mp) {
        if (p.second >= thres) {
            res.push_back(p.first);
        }
    }
    std::sort(res.begin(), res.end(), [](const std::string& a, const std::string& b) { return std::stoi(a) > std::stoi(b); });
    return res;
}


int main() {
    std::vector<std::string> data = {
            "345366 89921 45", 
            "029323 38239 23",
            "38239 345366 15", 
            "029323 38239 77",
            "345366 38239 23", 
            "029323 345366 13",
            "38239 38239 23"
    };
    std::vector<std::string> res(get_fraud_id(data, 3));
    for (const auto& r : res) {
        cout << r << " ";
    }
    return 0;
}
