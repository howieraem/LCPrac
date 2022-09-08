#
# @lc app=leetcode id=736 lang=python3
#
# [736] Parse Lisp Expression
#
from typing import *

# @lc code=start
class Solution:
    # T: O(n ^ 2)
    # S: O(n)
    def evaluate(self, expression: str) -> int:
        # Below are used to separate different layers (between the parentheses) of expressions
        tokens = [""]
        stack = []

        # Store intermediate symbol values
        d = dict()

        def eval(tokens: List[str]) -> str:
            if tokens[0] == "add":
                # tokens[1] and tokens[2] might be just a value or a symbol with a value
                x1 = int(d.get(tokens[1], tokens[1]))
                x2 = int(d.get(tokens[2], tokens[2]))
                return str(x1 + x2)
            elif tokens[0] == "mult":
                x1 = int(d.get(tokens[1], tokens[1]))
                x2 = int(d.get(tokens[2], tokens[2]))
                return str(x1 * x2)
            else:  # "let"
                # i += 2 because `tokens` will look like [..., "a", "1", "b", "2", ...].
                # Skip the last one because it's not updating the dictionary.
                for i in range(1, len(tokens) - 2, 2):
                    # Update the values of the symbols
                    d[tokens[i]] = d.get(tokens[i + 1], tokens[i + 1])
                # The last token cannot be a nested expression which is intercepted before entering this
                # so it can only be a symbol, an integer or ''
                return d.get(tokens[-1], tokens[-1])

        for c in expression:
            if c == '(':
                # Update the dictionary before entering the deeper layer
                if tokens[0] == "let":
                    eval(tokens)
                stack.append((tokens, dict(d)))  # copy both `tokens` and `d`
                tokens = [""]
            elif c == ')':
                # Get the current layer value
                val = eval(tokens)
                # Update the outer layer
                tokens, d = stack.pop()
                tokens[-1] += val
            elif c == ' ':  # Space characters separate symbols and values
                tokens.append("")
            else:
                tokens[-1] += c

        return int(tokens[0])

# @lc code=end

