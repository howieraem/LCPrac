from typing import List

class Solution:
    # T: O(len(message) + len(bannedWords))
    # S: O(len(bannedWords))
    def reportSpam(self, message: List[str], bannedWords: List[str]) -> bool:
        bannedWords = set(bannedWords)
        cnt = 0
        for m in message:
            cnt += (m in bannedWords)
            if cnt >= 2:
                return True
        return False
