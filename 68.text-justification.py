#
# @lc app=leetcode id=68 lang=python3
#
# [68] Text Justification
#
from typing import List

# @lc code=start
class Solution:
    # T: O(n * max_width)
    # S: O(max_width)
    def fullJustify(self, words: List[str], max_width: int) -> List[str]:
        N = len(words)
        res = []
        i = 0
        while i < N:
            j = i
            cur_width = 0
            # See what words can fit into the current line
            while j < N and cur_width + len(words[j]) + j - i <= max_width:
                cur_width += len(words[j])
                j += 1

            # Find the spaces between words on the current line
            spaces = 1
            extra_spaces = 0  # For the first few words on the current line, can have extra spaces
            if j - i != 1 and j != N:
                diff = max_width - cur_width
                spaces = diff // (j - i - 1)
                extra_spaces = diff % (j - i - 1)

            # Build the current line from words[i:j] with spaces
            line = [words[i]]
            line_width = len(words[i])
            for k in range(i + 1, j):
                line.append(' ' * spaces)
                line_width += spaces
                if extra_spaces > 0:
                    line.append(' ')
                    line_width += 1
                    extra_spaces -= 1
                line.append(words[k])
                line_width += len(words[k])

            # Add spaces to the right to fill the current line
            line.append(' ' * (max_width - line_width))

            res.append("".join(line)) # "".join(List[str]) is faster than string concats
            
            i = j
        
        return res

# @lc code=end

