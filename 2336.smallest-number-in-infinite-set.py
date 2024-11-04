# S: O(n)
class SmallestInfiniteSet(object):
    # T: O(1)
    def __init__(self):
        # may use SortedSet() if both popSmallest() and addBack() are called at same frequency
        self.popped_nums = set()
        self.min_to_be_popped = 1

    # T: O(n) worst
    def popSmallest(self):
        """
        :rtype: int
        """
        if len(self.popped_nums) > 0:
            cur_min = min(self.popped_nums)
            self.popped_nums.remove(cur_min)
            return cur_min
        else:
            cur_min = self.min_to_be_popped
            self.min_to_be_popped += 1
            return cur_min

    # T: O(1)
    def addBack(self, num):
        """
        :type num: int
        :rtype: None
        """
        if num < self.min_to_be_popped:
            self.popped_nums.add(num)


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)