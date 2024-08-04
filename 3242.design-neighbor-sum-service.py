class neighborSum(object):
    # T: O(n), n := number of cells
    # S: O(n)
    def __init__(self, grid):
        """
        :type grid: List[List[int]]
        """
        self.coord2val = {}
        self.val2coord = {}
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                self.coord2val[(i, j)] = grid[i][j]
                self.val2coord[grid[i][j]] = (i, j)
        self.m = len(grid)
        self.n = len(grid[0])

    # T: O(1)
    def adjacentSum(self, value):
        """
        :type value: int
        :rtype: int
        """
        coord = self.val2coord.get(value, None)
        if not coord:
            return 0
        i, j = coord
        adj_coords = []
        if i > 0:
            adj_coords.append((i - 1, j))
        if i < self.m - 1:
            adj_coords.append((i + 1, j))
        if j > 0:
            adj_coords.append((i, j - 1))
        if j < self.n - 1:
            adj_coords.append((i, j + 1))
        return sum(self.coord2val[k] for k in adj_coords)

    # T: O(1)
    def diagonalSum(self, value):
        """
        :type value: int
        :rtype: int
        """
        coord = self.val2coord.get(value, None)
        if not coord:
            return 0
        i, j = coord
        adj_coords = []
        if i > 0 and j > 0:
            adj_coords.append((i - 1, j - 1))
        if i < self.m - 1 and j > 0:
            adj_coords.append((i + 1, j - 1))
        if i < self.m - 1 and j < self.n - 1:
            adj_coords.append((i + 1, j + 1))
        if i > 0 and j < self.n - 1:
            adj_coords.append((i - 1, j + 1))
        return sum(self.coord2val[k] for k in adj_coords)


# Your neighborSum object will be instantiated and called as such:
# obj = neighborSum(grid)
# param_1 = obj.adjacentSum(value)
# param_2 = obj.diagonalSum(value)