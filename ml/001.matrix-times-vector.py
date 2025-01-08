# T: O(m * n)
# S: O(1) excl. output
def matrix_dot_vector(a: list[list[int|float]], b: list[int|float]) -> list[int|float]:
    m = len(a)
    if m == 0:
        return -1
    n = len(a[0])
    if n == 0 or len(b) == 0 or n != len(b):
        return -1
    
    res = [0] * m
    for i, row in enumerate(a):
        for j in range(n):
            res[i] += row[j] * b[j]
    return res
