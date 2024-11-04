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
    /*
    // Original BFS
    // T: O(n * l ^ 2 * s), n := len(wordList), l := avg(len(w) for w in wordList). s := alphabet size
    // S: O(n)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> ws(wordList.begin(), wordList.end());
        if (ws.find(endWord) == ws.end())  return 0;

        queue<string> q;
        int steps = 1;
        q.push(beginWord);

        while (!q.empty()) {
            int qs = q.size();
            while (qs-- > 0) {
                auto word = q.front(); q.pop();

                // Replace the i-th char with another possible char
                for (int i = 0; i < word.size(); ++i) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c != original) {
                            word[i] = c;
                            if (word == endWord)  return steps + 1;
                            if (ws.find(word) != ws.end()) {
                                q.push(word);  // IMPORTANT: push a copy
                                ws.erase(word);  // IMPORTANT: avoid producing duplicate intermediate word (acting as the visit set)
                            }
                        }
                    }
                    word[i] = original;  // IMPORTANT: undo the change before proceeding to change the next char (like backtracking?)
                }
            }
            ++steps;
        }
        return 0;   // sequence not found
    }
    */

    // Two-end BFS, same big-O complexity but actual cost reduced to 1/4 of original BFS 
    // T: O(n * (l / 2) ^ 2 * s), n := len(wordList), l := avg(len(w) for w in wordList). s := alphabet size
    // S: O(n)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> ws(wordList.begin(), wordList.end());
        if (ws.find(endWord) == ws.end())  return 0;

        unordered_set<string> begin_set, end_set;
        begin_set.insert(beginWord);
        end_set.insert(endWord);

        int steps = 2;  // IMPORTANT
        unordered_set<string> *p_begin_set, *p_end_set;
        while (begin_set.size() && end_set.size()) {
            if (begin_set.size() < end_set.size()) {
                p_begin_set = &begin_set;
                p_end_set = &end_set;
            } else {
                p_begin_set = &end_set;
                p_end_set = &begin_set;
            }

            unordered_set<string> tmp;
            for (auto it = p_begin_set->begin(); it != p_begin_set->end(); ++it) {
                // IMPORTANT: as we need to modify `word` to search, we can't do `for (auto& word : *p_begin_set)` 
                // because `word` in this case will be const
                auto word = *it;

                // Replace the i-th char with another possible char
                for (int i = 0; i < word.size(); ++i) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c != original) {
                            word[i] = c;
                            if (p_end_set->find(word) != p_end_set->end())  return steps;
                            if (ws.find(word) != ws.end()) {
                                tmp.insert(word);  // IMPORTANT: push a copy
                                ws.erase(word);  // IMPORTANT: avoid producing duplicate intermediate word
                            }
                        }
                    }
                    word[i] = original;  // IMPORTANT: undo the change before proceeding to change the next char
                }
            }
            ++steps;
            p_begin_set->swap(tmp);
        }

        return 0;
    }
};
// @lc code=end

