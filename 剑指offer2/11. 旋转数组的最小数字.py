class Solution:
    def minArray(self, numbers: List[int]) -> int:
        l, r = 0, len(numbers) - 1
        while l < r:
            m = l + ((r - l) >> 1)
            if numbers[m] > numbers[r]:
                # not sorted, left side is descending, 
                # so shift left boundary
                l = m + 1
            elif numbers[m] < numbers[r]:
                # sorted, right side is ascending,
                # so shift right boundary, but
                # not to m - 1 because we need
                # the lower bound
                r = m
            else:
                # found duplicates, cannot determine
                # ascending or descending, so linearly
                # shift the right boundary
                r -= 1
        return numbers[l]
