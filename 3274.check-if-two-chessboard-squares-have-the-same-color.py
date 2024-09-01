class Solution:
    # T: O(1)
    # S: O(1)
    def checkTwoChessboards(self, coordinate1: str, coordinate2: str) -> bool:
        x1 = ord(coordinate1[0]) - ord('a') + 1
        x2 = ord(coordinate2[0]) - ord('a') + 1
        y1 = int(coordinate1[1])
        y2 = int(coordinate2[1])
        
        dx = abs(x2 - x1)
        dy = abs(y2 - y1)
        
        dx_odd = (dx & 1) == 1
        dy_odd = (dy & 1) == 1

        return (dx_odd and dy_odd) or\
            (not dx_odd and not dy_odd)
