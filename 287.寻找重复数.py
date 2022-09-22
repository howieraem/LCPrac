#
# @lc app=leetcode.cn id=287 lang=python3
#
# [287] 寻找重复数
#

# @lc code=start
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        """Binary search approach which works under
        the assumption that numbers belong to [1, n].
        If there are n+1 numbers to be placed into
        n buckets, one of the buckets will contain
        at least two numbers. Time complexity O(nlog(n)).
        """
        n = len(nums)-1
        left, right, ans = 1, n, -1
        while left <= right:
            mid = (left + right) >> 1
            cnt = 0
            for num in nums:
                cnt += (num <= mid)
            if cnt <= mid:  
                # no duplicate exists on the left
                left = mid + 1
            else:
                right = mid - 1
                ans = mid
        return ans

    def findDuplicate(self, nums: List[int]) -> int:
        """Fast-slow pointers. Equivalent to finding
        a cycle in linked list. Time complexity
        O(N)."""
        slow = fast = 0
        while True:
            slow = nums[slow]           # 慢指针每次走一步
            fast = nums[nums[fast]]     # 快指针每次走两步
            if slow == fast:
                # 值相同，找到了环，退出
                break
        
        # 因为上面快慢指针是在环中某个位置相遇的，这个位置不一定是环的入口
        # 因此接下来我们还需要找环的入口，即重复的数字

        fast = 0    # 将快指针重新指向数组开头
        while True:
            # 开始寻找环的入口
            slow = nums[slow]       # 慢指针每次走一步
            fast = nums[fast]       # 快指针每次也走一步
            if slow == fast:
                # 相遇的位置一定是环的入口，即重复数字
                return slow

# @lc code=end

