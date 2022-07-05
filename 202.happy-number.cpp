/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
    int get_next(int n) {
        int sum = 0;
        while (n > 0) {
            int tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

public:
    // Similar idea to finding if a loop exists in linked list
    // T: O(log(n))
    // S: O(1)
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = get_next(slow);
            fast = get_next(get_next(fast));
        } while (slow != fast);
        return slow == 1;
    }
};
// @lc code=end

