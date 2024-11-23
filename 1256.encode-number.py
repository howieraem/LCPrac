#
# @lc app=leetcode id=1256 lang=python3
#
# [1256] Encode Number
#

# @lc code=start
class Solution:
    # bit manipulation + pattern recognition
    # T: O(log(num))
    # S: O(1) excl. output
    def encode(self, num: int) -> str:
        '''
        mapping = {
            '0': "",
            '1': "0",   # bin(1 + 1) & 0b1
            '2': "1",   # bin(2 + 1) & 0b1
            '3': "00",  # bin(3 + 1) & 0b11
            '4': "01",  # bin(4 + 1) & 0b11
            '5': "10",  # bin(5 + 1) & 0b11
            '6': "11",  # bin(6 + 1) & 0b11
            '7': "000"  # bin(7 + 1) & 0b111
        }
        '''
        # Using built-in bin()
        # bin_str = bin(num + 1)
        # return bin_str[3:]

        '''
        # Without using built-in bin() solution 1
        def num_to_bin(num: int) -> str:
            if num == 0:
                return "0"
            res = []
            while num != 0:
                res.append('1' if num & 1 else '0')
                num >>= 1
            res.reverse()
            return ''.join(res)

        bin_str = num_to_bin(num + 1)
        return bin_str[1:]
        '''

        # Without using built-in bin() solution 2
        num += 1
        res = []
        while num != 1:
            res.append('1' if num & 1 else '0')
            num >>= 1
        res.reverse()
        return ''.join(res)
        
# @lc code=end

