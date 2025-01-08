# T: O(m * n)
# S: O(1) excl. output
def transpose_matrix(a: list[list[int|float]]) -> list[list[int|float]]:
    m = len(a)
    if m == 0:
        return []
    n = len(a[0])
    if n == 0:
        return []
    
    res = [[0] * m for _ in range(n)]

    for i in range(m):
        for j in range(n):
            res[j][i] = a[i][j]
    return res
