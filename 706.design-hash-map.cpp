/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
struct Node {
    int k, v;
    Node* next;
    Node(int key, int val, Node* node) {
        k = key;
        v = val;
        next = node;
    }
};

// T: O(1) on average
// S: O(max)
class MyHashMap {
    // a prime number larger than the maximum no. of operations
    static const int SZ = 19997;
    static const int F = 12582917;
    Node* data[SZ];

    static int hash(int k) {
        return (int) ((long) k * F % SZ);
    }

public:
    void put(int key, int val) {
        // Find the node with k value equals key and remove it from the chain
        remove(key);

        int h = hash(key);
        // Create a new node and make it the head of the chain
        Node* node = new Node(key, val, data[h]);
        data[h] = node;
    }
    
    int get(int key) {
        int h = hash(key);
        Node *node = data[h];
        while (node) {
            if (node->k == key)  return node->v;
            node = node->next;
        }
        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        Node* pre = data[h];
        if (pre) {
            if (pre->k == key)  data[h] = pre->next;
            else {
                while (pre->next) {
                    if (pre->next->k == key) {
                        pre->next = pre->next->next;
                        break;
                    }
                    pre = pre->next;
                }
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

