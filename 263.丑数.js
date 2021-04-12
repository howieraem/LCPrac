/*
 * @lc app=leetcode.cn id=263 lang=javascript
 *
 * [263] 丑数
 */

// @lc code=start
/**
 * @param {number} num
 * @return {boolean}
 */
var isUgly = function(num) {
    if (num <= 0) {
        return false;
    }
    let uglys = new Set([1, 2, 3, 5]);

    while (true) {
        if (uglys.has(num)) {
            return true;
        }

        if (num % 2 === 0) {
            num /= 2;
        } else if (num % 3 === 0) {
            num /= 3;
        } else if (num % 5 === 0) {
            num /= 5;
        } else {
            return false;
        }
    }
};
// @lc code=end

