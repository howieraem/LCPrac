/*
 * @lc app=leetcode id=2018 lang=cpp
 *
 * [2018] Check if Word Can Be Placed In Crossword
 */
#include <bits/stdc++.h>

using std::string;
using std::vector;

// @lc code=start
class Solution {
    static constexpr int D[] {-1, 0, 1, 0, -1};

public:
    /*
    // Solution 1: Matrix traversal
    // T: O(m * n * l)
    // S: O(1)
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        const int m = board.size(), n = board[0].size(), l = word.size();

        // Need to check every cell, not just boundary cells, because the word can be placed 
        // after any blocked cells as long as there are no illegal leading/trailing cells.
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == ' ' || board[i][j] == word[0]) {
                    for (int d = 0; d < 4; ++d) {
                        // Check the following rules:
                        // 1. There must not be any empty cells ' ' or other lowercase letters directly left or right 
                        //    of the word if the word was placed horizontally.
                        // 2. There must not be any empty cells ' ' or other lowercase letters directly above or below 
                        //    the word if the word was placed vertically.
                        int prev_r = i - D[d], prev_c = j - D[d + 1];
                        if (0 <= prev_r && prev_r < m && 0 <= prev_c && prev_c < n && board[prev_r][prev_c] != '#') {
                            // leading cell is either ' ' or another char
                            continue;
                        }
                        int after_r = i + D[d] * l, after_c = j + D[d + 1] * l;
                        if (0 <= after_r && after_r < m && 0 <= after_c && after_c < n && board[after_r][after_c] != '#') {
                            // trailing cell is either ' ' or another char
                            continue;
                        }

                        // Check if the last char's location is in-bound
                        int last_r = after_r - D[d], last_c = after_c - D[d + 1];
                        if (last_r < 0 || last_r >= m || last_c < 0 || last_c >= n) {
                            continue;
                        }

                        // Check char-by-char following the current direction
                        int widx = 0, cur_r = i, cur_c = j;
                        while (widx < l) {
                            // either empty, or occupied by a char that matches the sequence
                            if (board[cur_r][cur_c] != ' ' && board[cur_r][cur_c] != word[widx]) {
                                break;
                            }
                            cur_r += D[d];
                            cur_c += D[d + 1];
                            ++widx;
                        }
                        if (widx == l) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    */

    // Solution 2: Matrix traversal + store num of letter matches in one direction (DP) 
    // T: O(m * n)
    // S: O(m * n)
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        
        // Generate board.transpose()
        vector<vector<char>> transposed(n, vector<char>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                transposed[j][i] = board[i][j];
            }
        }

        // Check horizontal, vertical, and their reverse directions
        return check(board, word) || check(board, string(rbegin(word), rend(word))) ||
                check(transposed, word) || check(transposed, string(rbegin(word), rend(word))) ;
    }

    bool check(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> n_matches(m, vector<int>(n, -1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 1. j == 0 || board[i][j - 1] == '#' -> potential start of a word
                // 2. j > 0 && n_matches[i][j - 1] != -1 -> middle of a word (partially matched)
                if (j == 0 || board[i][j - 1] == '#' || (j > 0 && n_matches[i][j - 1] != -1)) {
                    int next_pos = j == 0 ? 0 : n_matches[i][j - 1] + 1;  
                    
                    // one more char match
                    if (board[i][j] == ' ' || board[i][j] == word[next_pos]) {
                        if (next_pos == word.size() - 1) {
                            if (j == n - 1 || board[i][j + 1] == '#') {
                                // no trailing ' ' or another char
                                return true;
                            }
                        } else {
                            n_matches[i][j] = next_pos;
                        }
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

