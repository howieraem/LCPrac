/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */
#include <string>

using std::string;

// @lc code=start
struct Node {
    Node* next[26];
    bool isEnd;

    Node() : isEnd(false) {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
};

// T: O(l), l := len(word)
// S: O(l * alpha_size)
class Trie {
    Node *root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *tmp = root;
        for (const auto &c : word) {
            int cidx = c - 'a';
            if (!tmp->next[cidx]) {
                tmp->next[cidx] = new Node();
            }
            tmp = tmp->next[cidx];
        }
        tmp->isEnd = true;
    }
    
    bool search(string word) {
        Node *tmp = root;
        for (const auto& c : word) {
            int cidx = c - 'a';
            if (!tmp->next[cidx]) {
                return false;
            }
            tmp = tmp->next[cidx];
        }
        return tmp->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node *tmp = root;
        for (const auto& c : prefix) {
            int cidx = c - 'a';
            if (!tmp->next[cidx]) {
                return false;
            }
            tmp = tmp->next[cidx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

