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
    // Fast slow pointers (Floyd cycle detection algorithm)
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

    // More intuitive solution: use a hash set to simulate and check
    // if the intermediate number is either 1 (a happy number) or 
    // (not 1 and has appeared again, i.e. not a happy number)

    // The operation of keep summing the squares of the digits leads either to 1 or the loop of
    // 4 -> 16 -> 37 -> 58-> 89 -> 145 -> 42 -> 20 -> 4
    // Math proof: https://www.tandfonline.com/doi/abs/10.1080/00029890.1945.11991590
};
// @lc code=end

