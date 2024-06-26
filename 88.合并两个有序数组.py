#
# @lc app=leetcode.cn id=88 lang=python3
#
# [88] 合并两个有序数组
#

# @lc code=start
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        tail = m + n - 1
        m -= 1
        n -= 1
        while m >= 0 and n >= 0:
            if nums1[m] > nums2[n]:
                nums1[tail] = nums1[m]
                m -= 1
            else:
                nums1[tail] = nums2[n]
                n -= 1
            tail -= 1
        while n >= 0:
            # finished copying nums1 but not nums2
            nums1[tail] = nums2[n]
            n -= 1
            tail -= 1


# @lc code=end

