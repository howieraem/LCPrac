/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 */
#include <string>

using namespace std;

// @lc code=start
struct TrieNode {
    int val;
    int sum;
    TrieNode* next[26];
    TrieNode() {
        this->val = 0;
        this->sum = 0;
        for (int i = 0; i < 26; ++i) {
            this->next[i] = nullptr;
        }
    }
};

class MapSum {
public:
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* node = root;
        val -= get(key);
        for (auto &c : key) {
            node->sum += val;
            int i = c - 'a';
            if (!node->next[i]) {
                node->next[i] = new TrieNode();
            }
            node = node->next[i];
        }
        node->val += val;
        node->sum += val;
    }
    
    int sum(string prefix) {
        TrieNode* node = root;
        for (auto &c : prefix) {
            node = node->next[c - 'a'];
            if (!node)  return 0;
        }
        return node->sum;
    }

    int get(string s) {
        TrieNode* node = root;
        for (auto &c : s) {
            int i = c - 'a';
            if (!node->next[i])  return 0;
            node = node->next[i];
        }
        return node->val;
    }

private:
    TrieNode* root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end
