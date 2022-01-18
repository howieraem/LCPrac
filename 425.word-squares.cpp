/*
 * @lc app=leetcode id=425 lang=cpp
 *
 * [425] Word Squares
 */
#include <string>
#include <vector>

using std::string;
using std::vector;

// @lc code=start
struct TrieNode {
    vector<int> prefix;
    TrieNode* next[26];
    TrieNode() {
        memset(next, 0, sizeof(next));  // initialize all entries to nullptr
    }
};

class Solution {
public:
    // T: O((n ^ l) * l) worse case, n := len(words), l := len(words[0])
    // S: O(n * l)
    vector<vector<string>> wordSquares(vector<string>& words) {
        TrieNode *root = build(words);
        vector<vector<string>> res;
        vector<string> board(words[0].size());

        for (int i = 0; i < words.size(); ++i) {
            board[0] = words[i];
            dfs(board, words, root, 1, res);
        }
        return res;
    }

private:
    static TrieNode* build(vector<string>& words) {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            TrieNode *p = root;
            for (int j = 0; j < words[i].size() - 1; ++j) {
                int cidx = words[i][j] - 'a';
                if (!p->next[cidx]) {
                    p->next[cidx] = new TrieNode();
                }
                p = p->next[cidx];
                p->prefix.push_back(i);
            }
        }
        return root;
    }

    static void dfs(vector<string> &board, vector<string> &words, TrieNode *root, int row, vector<vector<string>> &res) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        TrieNode *p = root;
        // Try finding any prefixes vertically on the row-th column
        for (int i = 0; i < row; ++i) {
            int cidx = board[i][row] - 'a';
            if (!p->next[cidx])  return;
            p = p->next[cidx];
        }

        for (const int &i : p->prefix) {
            board[row] = words[i];
            dfs(board, words, root, row + 1, res);
        }
    }
};
// @lc code=end

