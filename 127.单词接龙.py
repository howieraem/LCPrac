#
# @lc app=leetcode.cn id=127 lang=python3
#
# [127] 单词接龙
#
from typing import List
from collections import defaultdict

# @lc code=start
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # Bidirectional BFS
        if endWord not in wordList:
            return 0
        
        # 提前构建图 -> 用generic state做key
        intermidiateWords = defaultdict(list)
        wordLen = len(beginWord)
        for word in wordList:
            for i in range(wordLen):
                intermidiateWords[word[:i] + '*' + word[i+1:]].append(word)
        
        wordLen = len(beginWord)
        beginQueue, endQueue, visited = [beginWord], [endWord], {beginWord}
        step = 0
        while beginQueue and endQueue:
            step += 1
            if len(beginQueue) > len(endQueue):
                beginQueue, endQueue = endQueue, beginQueue
            beginLen = len(beginQueue)
            for _ in range(beginLen):
                curWord = beginQueue.pop(0)
                for i in range(wordLen):
                    intermidiateCurWord = curWord[:i] + '*' + curWord[i+1:]
                    for word in intermidiateWords[intermidiateCurWord]:
                        if word in endQueue:
                            return step + 1
                        if word not in visited:
                            beginQueue.append(word)
                            visited.add(word)
        else:
            return 0
        
# @lc code=end
b = 'hit'
e = 'cog'
wordList = ['hit', 'hot', 'dot', 'dog', 'lot', 'log', 'cog']

print(Solution().ladderLength(b, e, wordList))
