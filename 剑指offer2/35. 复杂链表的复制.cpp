class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)  return nullptr;
        
        // Make a copy of each node and attach it after its original node 
        for (Node* node = head; node; node = node->next->next) {
            Node* nodeCopy = new Node(node->val);
            nodeCopy->next = node->next;
            node->next = nodeCopy;
        }

        // Now complete the random links
        for (Node* node = head; node; node = node->next->next) {
            Node* nodeCopy = node->next;
            if (node->random) {
                nodeCopy->random = node->random->next;
            }
        }

        // Decouple the copied nodes from the original nodes
        Node* headCopy = head->next;
        for (Node* node = head; node; node = node->next) {
            Node* nodeCopy = node->next;
            node->next = nodeCopy->next;
            if (nodeCopy->next) {
                nodeCopy->next = nodeCopy->next->next;
            }
        }
        return headCopy;
    }
};