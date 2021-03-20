#
# @lc app=leetcode.cn id=12 lang=python3
#
# [12] 整数转罗马数字
#

# @lc code=start
class Solution:
    _rules = (
            ('M', 1000),
            ('CM', 900), ('D', 500), ('CD', 400), ('C', 100),
            ('XC', 90), ('L', 50), ('XL', 40), ('X', 10),
            ('IX', 9), ('V', 5), ('IV', 4), ('I', 1),
        )

    def intToRoman(self, num: int) -> str:
        """Enumerates cases in `_rules`. Complexity O(1). Avoids if-else branches."""
        result = []

        for roman, dec in Solution._rules:
            if num >= dec:
                count, num = divmod(num, dec)
                result.extend([roman] * count)

        return ''.join(result)

    """
    Original solution:

    DICT1 = {
        0: 'I',
        1: 'X',
        2: 'C',
        3: 'M'
    }

    DICT5 = {
        0: 'V',
        1: 'L',
        2: 'D',
    }
    def intToRoman(self, num: int) -> str:
        if num < 1 or num > 3999:
            return ''
        nstr = '%d' % num
        ans = ''
        for i, c in enumerate(nstr[::-1]):
            if c == '0':
                continue
            ci = int(c)
            if ci < 4:
                ans = Solution.DICT1[i]*ci + ans
            elif ci == 4:
                ans = Solution.DICT1[i] + Solution.DICT5[i] + ans
            elif ci < 9:
                ans = Solution.DICT5[i] + Solution.DICT1[i]*(ci-5) + ans
            else:   # ci == 9
                ans = Solution.DICT1[i] + Solution.DICT1[i+1] + ans
        return ans
    """

    
# @lc code=end
s = Solution()
print(s.intToRoman(1994))
