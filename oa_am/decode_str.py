def decode_str(inp: str, n: int):
    mat = []
    start = 0
    row_len = len(inp) // n
    for _ in range(n):
        end = start + row_len
        mat.append(inp[start:end])
        start = end

    ans = ''
    for i in range(row_len):
        row, col = 0, i
        while row < n and col < row_len:
            if mat[row][col] == '_':
                ans += ' '
            else:
                ans += mat[row][col]
            row += 1
            col += 1
    return ans  # .rstrip()
