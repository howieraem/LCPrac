/*
 * @lc app=leetcode.cn id=264 lang=javascript
 *
 * [264] 丑数 II
 */

// @lc code=start
/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function(n) {
    let nums = [1, ];
    let i2 = 0, i3 = 0, i5 = 0;
    for (let i = 1; i < n; ++i) {
        let ugly = Math.min(nums[i2] * 2, nums[i3] * 3, nums[i5] * 5);
        nums.push(ugly);

        if (ugly === nums[i2] * 2) {
            ++i2;
        }
        if (ugly === nums[i3] * 3) {
            ++i3;
        }
        if (ugly === nums[i5] * 5) {
            ++i5;
        }
    }
    return nums.pop();      // returns last element in ugly number array
};
// @lc code=end

