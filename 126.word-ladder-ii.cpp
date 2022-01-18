/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n * l), n := len(wordList), l := avg(len(w) for w in wordList)
    // S: O(n)
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> ws(wordList.begin(), wordList.end());
        if (ws.find(endWord) == ws.end())  return {};
        
        queue<vector<string>> q;
        vector<vector<string>> ans;
        q.push({beginWord});
        unordered_set<string> lvlVis;

        while (q.size()) {
            int qs = q.size();
            lvlVis.clear();
            while (qs--) {
                auto cur_path = q.front(); q.pop();
                string last = cur_path.back();
                for (int i = 0; i < last.size(); ++i) {
                    auto tmp = last;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        tmp[i] = c;
                        if (ws.find(tmp) == ws.end())  continue;
                        auto new_path = cur_path;
                        new_path.push_back(tmp);
                        if (tmp == endWord) {
                            ans.push_back(new_path);
                        } else {
                            q.push(new_path);
                        }
                        // Cannot erase `tmp` from `ws` here because
                        // we need all the shortest paths
                        lvlVis.insert(tmp);
                    }
                }
            }
            for (const auto &w : lvlVis) {
                ws.erase(w);
            }
        }
        return ans;
    }
};
// @lc code=end

