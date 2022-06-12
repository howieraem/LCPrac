/*
 * @lc app=leetcode id=428 lang=cpp
 *
 * [428] Serialize and Deserialize N-ary Tree
 */
#include <bits/stdc++.h>

using std::deque;
using std::queue;
using std::string;
using std::vector;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
const string NULL_NODE_S = "X";
const string SEPARATOR = ",";

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res;
        serialize_helper(root, res);
        return res;
    }

    // O(n), n := total number of nodes
    void serialize_helper(Node* node, string& res) {
        if (node) {
            res += std::to_string(node->val);
            res += SEPARATOR;
            res += std::to_string(node->children.size());
            res += SEPARATOR;
            for (const auto& child : node->children) {
                serialize_helper(child, res);
            }
        } else {
            res += NULL_NODE_S;
            res += SEPARATOR;
        }
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        vector<string> v = str_split(data, SEPARATOR[0]);
        queue<string, deque<string>> q(deque<string>(v.begin(), v.end()));
        return deserialize_helper(q);
    }

    // T: Ω(len(string)) 
    Node* deserialize_helper(queue<string>& q) {
        string s = q.front(); q.pop();
        if (s == NULL_NODE_S)  return nullptr;
        int root_val = std::stoi(s);
        int n_child = std::stoi(q.front()); q.pop();

        Node* root = new Node(root_val);
        root->children.reserve(n_child);
        while (n_child-- > 0) {
            root->children.push_back(deserialize_helper(q));
        }
        return root;
    }

    vector<string> str_split(const string &s, char delim) {
        std::stringstream ss(s);
        string item;
        vector<string> res;
        while (std::getline(ss, item, delim)) {
            res.push_back(std::move(item));
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end

