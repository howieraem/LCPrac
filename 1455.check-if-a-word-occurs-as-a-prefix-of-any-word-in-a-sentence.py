#
# @lc app=leetcode id=1455 lang=python
#
# [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
#

# @lc code=start
class Solution(object):
    # Two pointers + Simplified KMP
    # T: O(n)
    # S: O(1)
    def isPrefixOfWord(self, sentence, searchWord):
        """
        :type sentence: str
        :type searchWord: str
        :rtype: int
        """
        # Idea: search for the first occurrence of `' ' + searchWord` 
        # in `' ' + sentence`, to simplify handling spaces between words.

        ans = 1  # simulate the added leading space
        
        i = 0
        j = 0
        while i < len(sentence) and j < len(searchWord):
            ans += (sentence[i] == ' ')
            if sentence[i] == searchWord[j]:
                if j > 0:
                    j += 1
                else:
                    # check if we matched a space or not
                    j = int(i == 0 or sentence[i - 1] == ' ')
            else:
                # mismatch, reset j
                j = 0
            
            i += 1
        
        return ans if j == len(searchWord) else -1
        
# @lc code=end

