#
# @lc app=leetcode id=929 lang=python3
#
# [929] Unique Email Addresses
#
from typing import *

# @lc code=start
class Solution:
    # Two pointers + hash set
    # T: O(n)
    # S: O(n)
    def numUniqueEmails(self, emails: List[str]) -> int:
        unique = set()

        for email in emails:
            parts = email.split('@')
            if len(parts) != 2:
                # bad email
                continue

            local_name = list(parts[0])
            n = len(local_name)
            i = 0
            j = 0
            while i < n:
                if local_name[i] == '+':
                    break
                elif local_name[i] != '.':
                    # overwrite '.' with valid characters
                    local_name[j] = local_name[i]
                    j += 1
                
                i += 1

            local_name = ''.join(local_name[:j])

            domain_name = parts[1]
            
            unique.add((local_name, domain_name))
        
        return len(unique)

# @lc code=end

