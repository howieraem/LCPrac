/*
 * @lc app=leetcode id=588 lang=cpp
 *
 * [588] Design In-Memory File System
 */
#include <map>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
/* Solution inspired by Trie */
class FileSystem {
    struct Node {
        map<string, Node*> children;    // keys are ordered, required by `ls()`
        string name, content;
        bool is_file;   // In reality, this is not the same as `!content.empty()`

        Node(string _name = "") : name(_name), is_file(false) {};
    };

    Node *root;

    // T: O(n * log(n)), n := the number of '/'
    Node* find(string path) {
        vector<string> dirs;
        string name;
        for (int i = 1; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (name.size()) {
                    dirs.push_back(name);
                    name.clear();
                }
                continue;
            } else {
                name.push_back(path[i]);
            }
        }
        if (name.size()) {  // don't forget the last one
            dirs.push_back(name);    
        }
        
        Node *cur = root;
        for (const string &d : dirs) {
            if (cur->children.find(d) == cur->children.end()) {
                cur->children[d] = new Node(d);
            }

            cur = cur->children[d];
            if (cur->is_file)  break;
        }
        return cur;
    }

public:
    FileSystem() {
        root = new Node();
    }
    
    vector<string> ls(string path) {
        vector<string> res;
        Node *cur = find(path);
        if (cur->is_file) {
            res.push_back(cur->name);
        } else {
            for (const auto &p : cur->children) {
                res.push_back(p.first);
            }
        }
        return res;
    }
    
    void mkdir(string path) {
        find(path); // just create entries in node maps
    }
    
    void addContentToFile(string filePath, string content) {
        Node *cur = find(filePath);
        cur->content += content;
        cur->is_file = true;
    }
    
    string readContentFromFile(string filePath) {
        Node *cur = find(filePath);
        return cur->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
// @lc code=end

