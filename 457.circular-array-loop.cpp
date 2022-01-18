/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    static int next_i(int i, const vector<int> &nums, const int &n) {
        // return i + nums[i] >= 0 ? (i + nums[i]) % n : n + ((i + nums[i]) % n);
        // return (i + nums[i]) % n + (i + nums[i] < 0) * n;
        return (i + nums[i] % n + n) % n;
    }

public:
    /*
    // Solution 1
    // Similar to finding a loop in Linkedlist, except that 
    // loops with only 1 element do not count.
    // T: O(n)
    // S: O(1)
    bool circularArrayLoop(vector<int>& nums) {
        const int n = nums.size();
        if (n < 2)  return false;

        for (int i = 0; i < n; ++i) {
            if (!nums[i])  continue;
            int slow = i, fast = next_i(slow, nums, n);

            // The slow and fast pointers must move in the same direction 
            // (both positive or both negative).
            while (nums[i] * nums[fast] > 0 && nums[i] * nums[next_i(fast, nums, n)] > 0) {
                if (slow == fast) {
                    if (slow == next_i(slow, nums, n))  break;  // loop length is 1
                    return true;
                }
                slow = next_i(slow, nums, n);
                fast = next_i(next_i(fast, nums, n), nums, n);
            }

            // No loop for the current i as the starting point.
            // Re-traverse from i and set element to 0 until
            // direction changes (the product becomes negative) or
            // a 0 is encountered. This will simplify subsequent
            // traversals.
            slow = i;
            while (nums[i] * nums[slow] > 0) {
                int tmp = next_i(slow, nums, n);
                nums[slow] = 0;
                slow = tmp;
            }
        }
        return false;
    }
    */


#define VISITED 2
#define VISITING 1
#define UNVISITED 0

    // Solution 2
    // Detect circle in a directed graph via DFS.
    // T: O(n) (actually faster than Solution 1)
    // S: O(n)
    bool circularArrayLoop(vector<int>& nums) {
        const int n = nums.size();
        vector<int> colors(n, UNVISITED);
        for (int i = 0; i < n; ++i) {
            if (colors[i] == UNVISITED && dfs(nums, colors, i, n))  return true;
        }
        return false;
    }

private:
    static bool dfs(const vector<int> &nums, vector<int> &colors, int i, const int &n) {
        if (colors[i] == VISITED)  return false;
        colors[i] = VISITING;
        int next = next_i(i, nums, n);
        if (next == i || nums[next] * nums[i] < 0) {
            colors[i] = VISITED;
            return false;
        }
        if (colors[next] == VISITING) {
            colors[i] = VISITED;
            return true;    // loop found
        }
        if (dfs(nums, colors, next, n))  return true;
        colors[i] = VISITED;
        return false;
    }
};
// @lc code=end

