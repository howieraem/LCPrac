/*
 * @lc app=leetcode id=255 lang=cpp
 *
 * [255] Verify Preorder Sequence in Binary Search Tree
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n) with stack, O(1) without stack
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        
        // The stack is for storing the left subtree.
        // stack<int> st;
        int i = -1;

        // Simulate the preorder traversal: cur_node => left_subtree => right_subtree,
        // and keep track of the lower bound
        for (const int& x : preorder) {
            if (x < low)  return false;
            /*
            // With stack
            while (st.size() && st.top() < x) {
                // Need to "place" the node `x` in the right_subtree of the node `low`.
                // The reason why we pop all smaller numbers is because from now on 
                // there is no way to attach numbers to those smaller numbers other 
                // than `low` as `x` comes in preorder sequence.
                low = st.top(); st.pop();
            }
            st.push(x); // continue traversal in the left_subtree
            */

            // Without stack
            while (i >= 0 && preorder[i] < x) {
                low = preorder[i--];
            }
            preorder[++i] = x;
        }
        return true;
    }
};
// @lc code=end

