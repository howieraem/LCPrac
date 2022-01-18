#
# @lc app=leetcode.cn id=160 lang=python3
#
# [160] 相交链表
#

# @lc code=start
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    '''
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None
        pointer_a, pointer_b = headA, headB
        counter_a = counter_b = 0

        while pointer_a.next:
            pointer_a = pointer_a.next
            counter_a += 1
        while pointer_b.next:
            pointer_b = pointer_b.next
            counter_b += 1
        
        if pointer_a is not pointer_b:
            return None
        diff = counter_a - counter_b
        if diff < 0:
            fast, slow = headB, headA
        else:
            fast, slow = headA, headB
        diff = abs(diff)
        for _ in range(diff):
            fast = fast.next
        while fast is not slow:
            fast = fast.next
            slow = slow.next
        return fast
    '''

    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        # much simpler solution: if reaching end of either list,
        # set the pointer to the head of another list.
        if not headA or not headB:
            return None
        pa, pb = headA, headB
        while pa is not pb:
            pa = pa.next if pa else headB
            pb = pb.next if pb else headA
        # If `pa` and `pb` both become null, then they have iterated both lists completely and 
        # there is no intersection. If they are not null, then they point to the intersection.
        return pa

'''
def array2linkedlist(l):
    if not l:
        return None
    l = [ListNode(v) for v in l]
    for i in range(len(l)-1):
        l[i].next = l[i+1]
    return l[0]
'''
        
# @lc code=end
