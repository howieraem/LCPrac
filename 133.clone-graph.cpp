/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */
#include <bits/stdc++.h>

using std::vector;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // BFS-based
    // T: O(V + E)
    // S: O(V + E)
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;  // IMPORTANT
        std::queue<Node*> q;
        std::unordered_map<Node*, Node*> node_copy;

        auto copy = new Node(node->val);
        q.push(node);
        node_copy[node] = copy;

        while (q.size()) {
            auto cur = q.front(); q.pop();
            auto cur_copy = node_copy[cur];
            for (const auto& neighbor : cur->neighbors) {
                auto it = node_copy.find(neighbor);
                if (it == node_copy.end()) {
                    // neighbor not yet visited
                    auto neighbor_copy = new Node(neighbor->val);
                    q.push(neighbor);
                    node_copy[neighbor] = neighbor_copy;
                    cur_copy->neighbors.push_back(neighbor_copy);
                } else {
                    // neighbor already visited
                    cur_copy->neighbors.push_back(it->second);
                }
            }
        }
        return copy;
    }

    /*
    // DFS-based
    // T: O(V + E)
    // S: O(V + E)
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;  // IMPORTANT
        std::unordered_map<Node*, Node*> node_copy;
        return dfs(node, node_copy);
    }

private:
    Node* dfs(Node* node, std::unordered_map<Node*, Node*>& node_copy) {
        Node* copy = new Node(node->val);
        node_copy[node] = copy;
        for (const auto& neighbor : node->neighbors) {
            auto it = node_copy.find(neighbor);
            if (it == node_copy.end()) {  // neighbor not yet visited
                copy->neighbors.push_back(dfs(neighbor, node_copy));
            } else {  // neighbor already visited
                copy->neighbors.push_back(it->second);
            }
        }
        return copy;
    }
    */
};
// @lc code=end

