#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(0)  # dummy头结点，无存储，指向链表第一个结点
        node = head         # 初始化链表结点
        carry = 0           # 初始化 进一 的数
        while l1 or l2:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            node_val = x + y + carry              # 对每一位求和
            carry = node_val // 10                # 地板除，求进一（其为0或1）
            node.next = ListNode(node_val % 10)   # 取余数，求本位结点
            if l1:                           # 求空否，防止出现无后继结点
                l1 = l1.next       
            if l2:                           # 同上
                l2 = l2.next
            node = node.next                 # 更新指针
        if carry != 0:                       # 验证最后一位相加是否需 进一
            node.next = ListNode(1)
        return head.next                     # 返回头结点的下一个结点，即链表的第一个结点

    """
    This is no need to record elements of each list before.
    Original answer:

    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l1_nums = [l1.val]
        l2_nums = [l2.val]
        while l1.next is not None:
            l1 = l1.next
            l1_nums.append(l1.val)
        while l2.next is not None:
            l2 = l2.next
            l2_nums.append(l2.val)
        len1, len2 = len(l1_nums), len(l2_nums)
        if len2 > len1:
            l2_nums, l1_nums, len2, len1 = l1_nums, l2_nums, len1, len2
        l2_nums.extend([0]*(len1-len2))
        prev_node = None
        first_node = None
        carry = 0
        for l1_num, l2_num in zip(l1_nums, l2_nums):
            nl_val = l1_num+l2_num+carry
            carry = nl_val >= 10
            if carry:
                nl_val -= 10
            curr_node = ListNode(nl_val)
            if prev_node is not None:
                prev_node.next = curr_node
            else:
                first_node = curr_node
            prev_node = curr_node
        if carry:
            prev_node.next = ListNode(1)
        return first_node
    """

# @lc code=end
