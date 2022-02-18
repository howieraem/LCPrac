#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个正序数组的中位数
#
from typing import List

# @lc code=start
class Solution:
    """
    这题很自然地想到归并排序，再取中间数，但是复杂度是nlogn，题目要求logn，
    所以要用二分法来巧妙地进一步降低时间复杂度。
    
    中位数定义：
    左堆 -|- 中位数元素（总数奇数为1个，否则为2个） -|- 右堆
    where左堆元素数量 == 右堆元素数量
    """
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        """
        思想1：利用总体中位数的性质和左右中位数之间的关系来把所有的数先分成两堆，然后再在两堆的边界返回答案。
            例如：
                nums1 = [a1, a2, a3, a4, a5]
                nums2 = [b1, b2, b3, b4, b5, b6, b7]
                len(num2) >= len(nums1)

                找到两个数组的切分位置，如：
                nums1 = [a1, a2, -|- a3, a4, a5]
                nums2 = [b1, b2, b3, b4, -|- b5, b6, b7]
                
                b5 >= a2 && a3 >= b4
                那么中位数为(max(a2+b4)+min(a3+b5))/2；

                若总元素数量是奇数（例如从原nums2去掉b7），则中位数为min(a3+b5)。

            时间复杂度O(log(min(l1, l2)))，空间复杂度O(1)
        """
        l1, l2 = len(nums1), len(nums2)
        # 让nums2成为更长的那一个数组
        if l1 > l2:
            nums1, nums2, l1, l2 = nums2, nums1, l2, l1
        
        # 如果两个都为空的异常处理
        if not l2:
            raise ValueError

        # nums1中index在mid1左边的都被分到左堆，nums2中mid2左边的都被分到左堆
        min1, max1 = 0, l1
        
        while min1 <= max1:
            mid1 = min1 + (max1-min1)//2    # 二分
            # 左堆最大的只有可能是nums1[mid1-1], nums2[mid2-1]
            # 右堆最小只有可能是nums1[mid1], nums2[mid2]
            # 让左右堆元素数量大致相等需要满足的条件是mid1+mid2 = l1-mid1+l2-mid2 即 mid2 = (m+n-2*mid1)//2
            # 为什么是大致呢？因为有总数为奇数的情况，这里用向下取整数操作，所以如果是奇数，右堆会多1
            mid2 = (l1+l2-2*mid1)//2 
            
            # and前面的判断条件是为了处理边界情况（其中一个数组的mid指针已经移到边界），保证不出IndexError
            if mid1 > 0 and nums1[mid1-1] > nums2[mid2]:
                # mid1太大了，这里精确查找，不是左闭右开，而是双闭区间，所以直接移动一位
                max1 = mid1-1
            elif mid1 < l1 and nums2[mid2-1] > nums1[mid1]:
                min1 = mid1+1
            # 满足条件
            else:
                # 依次得到左堆最大和右堆最小
                if mid1 == l1:      # 边界情况处理 
                    minright = nums2[mid2]
                elif mid2 == l2:    # 边界情况处理 
                    minright = nums1[mid1]
                else:
                    minright = min(nums1[mid1],nums2[mid2])        
                    
                if mid1 == 0:       # 边界情况处理 
                    maxleft = nums2[mid2-1]
                elif mid2 == 0:     # 边界情况处理 
                    maxleft = nums1[mid1-1]
                else:
                    maxleft = max(nums1[mid1-1],nums2[mid2-1])
                
                # 前面也提过，因为取中间的时候用的是向下取整，所以如果总数是奇数的话，
                # 应该是右边个数多一些，边界的minright就是中位数
                if (l1+l2) % 2:
                    return minright 
     
                # 否则我们在两个值中间做个平均
                return (maxleft + minright)/2

# @lc code=end
# s = Solution()
# print(s.findMedianSortedArrays([5, 6, 7], [1, 2, 3, 4, 8, 9, 10]))
