/*
 * @lc app=leetcode id=1804 lang=cpp
 *
 * [1804] Implement Trie II (Prefix Tree)
 */
#include <string>
#include <vector>

using std::string;
using std::vector;

// @lc code=start
struct Node {
    vector<Node*> next;
    int wCnt, pCnt;

    Node() : next(26, nullptr), wCnt(0), pCnt(0) {}
};


class Trie {
    Node *root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *tmp = root;
        for (auto &c : word) {
            int cidx = c - 'a';
            if (!tmp->next[cidx]) {
                tmp->next[cidx] = new Node();
            }
            tmp = tmp->next[cidx];
            tmp->pCnt++;
        }
        tmp->wCnt++;
    }
    
    int countWordsEqualTo(string word) {
        Node *tmp = root;
        for (auto &c : word) {
            int cidx = c - 'a';
            if (!tmp->next[cidx] || !tmp->next[cidx]->pCnt) {
                return 0;
            }
            tmp = tmp->next[cidx];
        }
        return tmp->wCnt;
    }
    
    int countWordsStartingWith(string prefix) {
        Node *tmp = root;
        for (auto &c : prefix) {
            int cidx = c - 'a';
            if (!tmp->next[cidx]) {
                return 0;
            }
            tmp = tmp->next[cidx];
        }
        return tmp->pCnt;
    }
    
    void erase(string word) {
        // Assuming word is in the Trie.
        // Although not required by this question, may need to
        // free the memory occupied by unused nodes in reality.
        Node *tmp = root;
        for (auto &c : word) {
            // If word is not in the Trie, check and return here
            tmp = tmp->next[c - 'a'];
            tmp->pCnt--;
        }
        tmp->wCnt--;
    }

    // Extra: find all words with prefix
    // This solution does not require modifying the node, though one 
    // may store the actual words at the nodes
    vector<string> search(string prefix) {
        Node *tmp = root;
        for (auto &c : prefix) {
            int cidx = c - 'a';
            if (!tmp->next[cidx]) {
                return {};
            }
            tmp = tmp->next[cidx];
        }
        vector<string> res;
        traverse(prefix, tmp, res);
        return res;
    }

    void traverse(string &prefix, Node const *node, vector<string> &res) {
        for (int i = 0; i < node->wCnt; ++i) {
            res.push_back(prefix);
        }

        for (int i = 0; i < 26; ++i) {
            Node const *child = node->next[i];
            if (child) {
                prefix.push_back(static_cast<char>(i + 'a'));
                traverse(prefix, child, res);
                prefix.pop_back();
            }
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
// @lc code=end

