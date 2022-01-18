#
# @lc app=leetcode.cn id=43 lang=python3
#
# [43] 字符串相乘
#

# @lc code=start
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        """
        Performs multiplication on every k digits between num1 and num2, and then sums the intermediate
        results up.

        Let lists a and b be substrings split by every k steps reversely from num1 and num2 respectively. 
        Then we have
            a = a[0]*10^(0*k) + a[1]*10^(1*k) + ... + a[n1]*10^(n1*k)
            b = b[0]*10^(0*k) + b[1]*10^(1*k) + ... + b[n2]*10^(n2*k)
            n1, n2 = len(a), len(b)
        Since
            (a0+a1)*(b0+b1) = a0*b0 + a1*b0 + b0*a1 + a1*b1
        The product is then
            a*b = \
                (a[0]*b[0])*10^(0*k) + (a[0]*b[1]+a[1]*b[0])*10^(1*k) + ... \
                + (a[0]*b[i+j]+a[1]*b[i+j-1] + ... \
                + a[i]*b[j]+...+a[i+j]*b[0])*10^((i+j)*k) + ... \
                + (a[n1]*b[n2])*10^((n1+n2)*k)

        Considering the string length of 2**31, k should be no more than 3. The larger k, the more efficient.

        Notes: Though large number is not a problem for python, it can be a problem in Java/C++.
            Thus, `return str(int(num1)*int(num2))` is not a legit answer.
        """
        num1_list, num2_list, k = [], [], 2
        while len(num1) > k:
            num1_list.append(num1[-k:])
            num1 = num1[:-k]
        if len(num1):
            # the remaining digit(s) for num1
            num1_list.append(num1)
        while len(num2) > k:
            num2_list.append(num2[-k:])
            num2 = num2[:-k]
        if len(num2):
            # the remaining digit(s) for num2
            num2_list.append(num2)
        
        res_list = [0] * (len(num1_list)+len(num2_list))
        for i in range(len(num1_list)):
            for j in range(len(num2_list)):
                res_list[i+j] += int(num1_list[i]) * int(num2_list[j])

        # `res_list` represents a[i]*b[j] terms without `*10^(n*k)`.
        # Summation is also done on every k digits of the intermediate
        # results.
        # print(res_list)
        res, carry = [], 0
        for i in range(len(res_list)):
            res_tmp = str(res_list[i] + carry)
            if len(res_tmp) > k:
                res.append(res_tmp[-k:])
                carry = int(res_tmp[:-k])
            else:
                res.append('0'*(k - len(res_tmp)) + res_tmp)
                carry = 0

        # Finally, reverse the string and remove leading zeros as summation started from the smaller digits.
        res = ''.join(res[::-1]).lstrip('0')
        return res if res else '0'

# @lc code=end
# s = Solution()
# print(s.multiply('1234', '5678'))
