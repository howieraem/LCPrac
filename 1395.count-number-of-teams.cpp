/*
 * @lc app=leetcode id=1395 lang=cpp
 *
 * [1395] Count Number of Teams
 */
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    /*
    // Solution 1
    // T: O(n ^ 2)
    // S: O(1)
    int numTeams(vector<int>& rating) {
        const int n = rating.size();
        int ans = 0;

        // For each soldier, count how many soldiers on the left and right 
        // that have less and greater ratings.
        for (int i = 0; i < n; ++i) {
            int leftLess = 0, leftGreater = 0, rightLess = 0, rightGreater = 0;
            for (int j = 0; j < n; ++j) {
                if (rating[i] < rating[j]) {
                    if (j > i)  ++rightGreater;
                    else  ++leftGreater;
                } else if (rating[i] > rating[j]) {
                    if (j > i)  ++rightLess;
                    else  ++leftLess;
                } // else i == j, skip
            }
            ans += leftLess * rightGreater + leftGreater * rightLess;
        }
        return ans;
    }
    */

    // Solution 2 based on binary indexed tree (Fenwick tree，树状数组)
    // https://en.wikipedia.org/wiki/Fenwick_tree
    // T: O(n * max(rating))
    // S: O(max(rating))
    int numTeams(vector<int>& rating) {
        const int n = rating.size();
        int leftTree[MAX_VAL] {0}, rightTree[MAX_VAL] {0};
        for (const int &r : rating) {
            update(rightTree, r, 1);
        }

        int ans = 0;
        for (const int &r : rating) {
            update(rightTree, r, -1);
            ans += prefixSum(leftTree, r - 1) * suffixSum(rightTree, r + 1) + suffixSum(leftTree, r + 1) * prefixSum(rightTree, r - 1);
            update(leftTree, r, 1);
        }
        return ans;
    }

private:
    static const int MAX_VAL = 1e5 + 1;  // the maximum possible value of ratings

    /**
     * In a Binary Indexed Tree: 
     * - To query the tree, find the parent of an element by resetting its rightmost set bit 
     *   (i.e. idx -= idx & (-idx))
     * - To update the tree, keep adding least significant bit to the current index to find all the elements to update 
     *   (i.e. idx += idx & (-idx))
     * 
     * In the implementation below, x & (-x) gets the value represented by the lowest set bit in x 
     * (when all other bits are clear). Examples: 2 = 0b10, 2 & -2 = 2; 3 = 0b11, 3 & -3 = 1.
     */ 

    // T: O(log(idx))
    void update(int tree[], int idx, int val) {
        while (idx < MAX_VAL) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }

    // Returns the number of elements on the left
    // T: O(log(idx))
    int prefixSum(int tree[], int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

    // Returns the number of elements on the right
    int suffixSum(int tree[], int idx) {
        return prefixSum(tree, MAX_VAL - 1) - prefixSum(tree, idx - 1);
    }
};
// @lc code=end

