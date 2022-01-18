class Solution:
    def isNumber(self, s: str) -> bool:
        if not s:
            # '' or None
            return False
        has_e = has_num = has_dot = False
        s = s.strip()
        for i, c in enumerate(s):
            if c.isdigit():
                has_num = True
            elif c == '.':
                if has_dot or has_e:
                    return False
                has_dot = True
            elif c == 'e' or c == 'E':
                if has_e or not has_num:
                    return False
                has_e = True
                has_num = False
            elif c == '-' or c == '+':
                if i > 0 and s[i - 1] != 'e' and s[i - 1] != 'E':
                    return False
            else:
                return False
        return has_num
