/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
/*
// Solution with STL list and list iterator, 
// less code but slower
class LRUCache {
    int cap;
    list<int> lru;
    unordered_map<int, list<int>::iterator> mp;
    unordered_map<int, int> kv;

public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        if (kv.find(key) == kv.end())  return -1;
        updateLRU(key);
        return kv[key];
    }
    
    void put(int key, int value) {
        if (kv.size() == cap && kv.find(key) == kv.end()) {
            mp.erase(lru.back());
            kv.erase(lru.back());
            lru.pop_back();
        }
        updateLRU(key);
        kv[key] = value;
    }

private:
    void updateLRU(int key) {
        if (kv.find(key) != kv.end()) {
            lru.erase(mp[key]);
        }
        lru.push_front(key);
        mp[key] = lru.begin();
    }
};
*/

struct Node {
    int k, v;
    Node *pre, *nxt;
    Node() : k(0), v(0), pre(nullptr), nxt(nullptr) {}
    Node(int _k, int _v) : k(_k), v(_v), pre(nullptr), nxt(nullptr) {}
};

class LRUCache {
    Node *head, *tail;
    int cap;
    unordered_map<int, Node*> mp;

    void addToHead(Node* node) {
        node->pre = head;
        node->nxt = head->nxt;
        head->nxt->pre = node;
        head->nxt = node;
    }

    void removeNode(Node* node) {
        node->nxt->pre = node->pre;
        node->pre->nxt = node->nxt;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addToHead(node);
    }

    Node* removeTail() {
        Node *node = tail->pre;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node();
        tail = new Node();
        head->nxt = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end())  return -1;
        Node* node = mp[key];
        moveToHead(node);
        return node->v;
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            Node* node = new Node(key, value);
            mp[key] = node;
            addToHead(node);
            if (mp.size() > cap) {
                Node* removed = removeTail();
                mp.erase(removed->k);
                delete removed;
            }
        } else {
            Node* node = mp[key];
            node->v = value;
            moveToHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
