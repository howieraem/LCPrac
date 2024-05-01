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
    int n_words;

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

    void backtrack(vector<vector<char>> &board, int r, int c, TrieNode *p, vector<string> &res) {
        if (n_words == 0)  return;
        char ch = board[r][c];
        if (ch == VIS_C || !p->next[ch - 'a'])  return;
        p = p->next[ch - 'a'];
        if (p->word.size()) {
            // By storing word in trie node and clearing it once visited, 
            // there is no need to use a hash set to filter duplicates in res
            res.push_back(std::move(p->word));
            // p->word.clear();
            --n_words;
        }

        board[r][c] = VIS_C;
        for (int d = 0; d < 4; ++d) {
            int nr = r + D[d], nc = c + D[d + 1];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[nr].size()) {
                backtrack(board, nr, nc, p, res);
            }
        }
        board[r][c] = ch;
    }

public:
    // T: O(3 ^ l * m * n), l := max word length
    // S: O(l + l * s) = O(l * s) recursive stack and trie, s := alphabet size (if not storing string references, need to mult by the number of words too)
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n_words = words.size();
        build_trie(words);
        vector<string> res;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                backtrack(board, i, j, root, res);
                if (n_words == 0) {
                    // IMPORTANT: prevent unnecessary recursions if all words found
                    return res;
                }
            }
        }
        return res;
    }
};
// @lc code=end

