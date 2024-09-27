class Solution:
    # T: O(n)
    # S: O(1)
    def compressedString(self, word: str) -> str:
        THRES = 9
        res = []
        cur_cnt = 1

        for i in range(1, len(word)):
            if word[i] == word[i - 1] and cur_cnt < THRES:
                cur_cnt += 1
                continue
            res.append(str(cur_cnt))
            res.append(word[i - 1])
            cur_cnt = 1

        # don't forget last char
        res.append(str(cur_cnt))
        res.append(word[-1])

        return ''.join(res)
