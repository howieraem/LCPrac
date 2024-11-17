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

// Math + linked list
// T: O(1) on average
// S: O(max)
class MyHashMap {
    // prime numbers are helpful for avoiding collisions
    static const int SZ = 19997;  // a prime number larger than the maximum no. of operations
    static const int F = 12582917;   // another large prime number
    Node* data[SZ];

    static int hash(int key) {
        return (int) ((long) key * F % SZ);
        // A more realistic hash function: (((key * F) & (1 << 20) - 1) >> 5) % SZ, but not necessary for this problem
    }

public:
    void put(int key, int val) {
        // Find the node with node.k == key and remove it from the chain
        remove(key);

        int h = hash(key);
        // Create a new node and make it the head of the chain
        Node* node = new Node(key, val, data[h]);
        data[h] = node;
    }
    
    int get(int key) {
        int h = hash(key);
        Node *node = data[h];
        while (node != nullptr) {
            if (node->k == key) {
                return node->v;
            }
            // collision, check next one
            node = node->next;
        }
        // key doesn't exist
        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        Node* node = data[h];
        if (node != nullptr) {
            if (node->k == key) { 
                data[h] = node->next;
                delete node;
            } else {
                // collision, search for the matching key
                while (node->next != nullptr) {
                    Node* tmp = node->next;
                    if (tmp->k == key) {
                        node->next = tmp->next;
                        delete tmp;
                        break;
                    }
                    node = node->next;
                }
            }
        }
        // do nothing if key doesn't exist
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

