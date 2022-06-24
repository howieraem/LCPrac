/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
#define VIS_C '#'

struct TrieNode {
    vector<TrieNode*> next;
    string word;

    TrieNode() : next(26, nullptr) {}
};

class Solution {
    static constexpr int D[] {0, 1, 0, -1, 0};
    TrieNode *root;

    void build_trie(const vector<string> &words) {
        root = new TrieNode();
        for (const string &w : words) {
            TrieNode *p = root;
            for (const auto &c : w) {
                int i = c - 'a';
                if (!p->next[i]) {
                    p->next[i] = new TrieNode();
                }
                p = p->next[i];
            }
            p->word = w;
        }
    }

    void dfs(vector<vector<char>> &board, int r, int c, TrieNode *p, vector<string> &res) {
        char ch = board[r][c];
        if (ch == VIS_C || !p->next[ch - 'a'])  return;
        p = p->next[ch - 'a'];
        if (p->word.size()) {
            res.push_back(p->word);
            p->word.clear();    // no need to use a hash set to filter duplicates in res
        }

        board[r][c] = VIS_C;
        for (int d = 0; d < 4; ++d) {
            int nr = r + D[d], nc = c + D[d + 1];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[nr].size()) {
                dfs(board, nr, nc, p, res);
            }
        }
        board[r][c] = ch;
    }

public:
    // T: O(3 ^ l * m * n), l := max word length
    // S: O(m * n + l * s) recursive stack and trie, s := alphabet size
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        build_trie(words);
        vector<string> res;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                dfs(board, i, j, root, res);
            }
        }
        return res;
    }
};
// @lc code=end
