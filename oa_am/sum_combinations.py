def print_sum_combinations(target: int):
    res = []

    def backtrack(path, start, cur_sum):
        if cur_sum == target:
            res.append(path[:])

        for i in range(start, target):
            tmp_sum = cur_sum + i
            if tmp_sum > target:
                return
            path.append(i)
            backtrack(path, i, tmp_sum)
            path.pop()

    backtrack([], 1, 0)

    for ret in res:
        for n in ret:
            print(n, end=" ")
        print()
