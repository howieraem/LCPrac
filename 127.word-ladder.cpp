/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> ws(wordList.begin(), wordList.end());
        if (ws.find(endWord) == ws.end())  return 0;

        queue<string> q;
        int steps = 1;
        q.push(beginWord);

        while (q.size()) {
            int qs = q.size();
            while (qs--) {
                auto cur = q.front(); q.pop();
                for (int i = 0; i < cur.size(); ++i) {
                    auto tmp = cur;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        tmp[i] = c;
                        if (tmp == endWord)  return steps + 1;
                        if (ws.find(tmp) != ws.end()) {
                            q.push(tmp);
                            ws.erase(tmp);
                        }
                    }
                }
            }
            ++steps;
        }
        return 0;   // sequence not found
    }
};
// @lc code=end

