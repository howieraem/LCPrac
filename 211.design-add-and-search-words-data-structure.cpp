/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
// S: O(s * n), s := alphabet size, n := max word len
class WordDictionary {
    struct TrieNode {
        // std::vector<TrieNode*> children;
        TrieNode* children[26] {};
        bool is_word = false;
        // TrieNode() : children(26, nullptr), is_word(false) {}
    };

    TrieNode* root;

    bool search(const string& word, int cur_idx, TrieNode* cur_node) {
        if (cur_idx == word.size()) {
            return cur_node->is_word;
        }
        if (word[cur_idx] == '.') {
            ++cur_idx;
            for (auto& child : cur_node->children) {
                if (child != nullptr && search(word, cur_idx, child)) {
                    return true;
                }
            }
            return false;
        } else {
            auto next_node = cur_node->children[word[cur_idx] - 'a'];
            return next_node != nullptr && search(word, cur_idx + 1, next_node);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // T: O(len(word))
    void addWord(string word) {
        TrieNode *cur = root;
        for (const char& c : word) {
            int ci = c - 'a';
            if (cur->children[ci] == nullptr) {
                cur->children[ci] = new TrieNode();
            }
            cur = cur->children[ci];
        }
        cur->is_word = true;
    }
    
    // T: O(s * len(word)) worst case, s := alphabet size
    // S: O(len(word)) recursion stack
    bool search(string word) {
        return search(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

