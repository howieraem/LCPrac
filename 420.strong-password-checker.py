#
# @lc app=leetcode id=420 lang=python3
#
# [420] Strong Password Checker
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def strongPasswordChecker(self, password: str) -> int:
        n = len(password)
        missing_lower = missing_upper = missing_digit = True
        replace = 0
        del_one = del_two = 0

        i = 0
        while i < n:
            c = password[i]
            missing_lower &= not c.islower()
            missing_upper &= not c.isupper()
            missing_digit &= not c.isdigit()
            if i >= 2 and password[i] == password[i - 1] == password[i - 2]:
                length = 3
                i += 1

                while i < n and password[i] == password[i - 1]:
                    c = password[i]
                    missing_lower &= not c.islower()
                    missing_upper &= not c.isupper()
                    missing_digit &= not c.isdigit()
                    length += 1
                    i += 1

                replace += length // 3
                del_one += (length % 3 == 0)
                del_two += (length % 3 == 1)
            else:
                i += 1

        missing_types = missing_lower + missing_upper + missing_digit

        if n < 6:
            return max(missing_types, 6 - n)
        elif n <= 20:
            return max(missing_types, replace)
        else:
            """
            If length of the string is larger than 20, we will need to delete some chars 
            and appropriate deletion can reduce the number of replacements needed to break 
            repeating sequences after deletion.

            For any repeating sequences with length % 3 == 0, we need to make length // 3 
            replacements and we can reduce the number of replacements by 1 by deleting 
            1 character. Similarly, for any repeating sequences with length % 3 == 1, 
            we can reduce 1 replacement by deleting 2 characters.
            """
            to_del = n - 20  # if length > 20, there must be deletions
            del_two <<= 1  # each del_two operation deletes 2 chars, so multiply by 2

            # Case 1: aaa ... violation can be resolved by deleting last 'a'. 
            # So we subtract those deletions from the number of needed replacements.
            replace -= min(to_del, del_one)

            # Case 2: aaaa ... violation can only be resolved by deleting last 'aa' only. 
            # Since we already used deletions for case 1, we subtract those here. Since we 
            # must delete 2 chars to resolve each violation, we can only use delete // 2 deletions.
            replace -= min(max(to_del - del_one, 0), del_two) >> 1

            # Case 3: aaaaa ... violation can only be resolved by deleting last 'aaa' only. 
            # We must again exclude cases 1 and 2 here. We can only resolve (to_del - del_one - del_two) // 3 
            # violations.
            replace -= max(to_del - del_one - del_two, 0) // 3
            return to_del + max(missing_types, replace)
        
# @lc code=end

