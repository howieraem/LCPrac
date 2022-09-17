"""
Given an infinite number line, two types of operations: 
1. [1, x] - builds an obstacle at coordinate x along the number line. It is guaranteed that coordinate x does not contain any obstacles when the operation is performed. 
2. [2, x, size] - checks whether it's possible to build a block occupying coordinates between x-size, x-size+1,..., x-1 along the number line. Returns 1 if it is possible, i.e. there are no obstacles at the occupied coordinates, and return 0 otherwise.

Operations are provided as follows:

[[1, 3]
 [1, -10]
 [2, -5, 7]
 [2, 20, 3]]

the result is expected as a binary string, for the above example, it would be "01"
"""
def solve(operations):
    d = []
    st = []
    for op in operations:
        if op[0] == 1:
            bisect.insort(d, op[1])
        elif op[0] == 2:
            x, size = op[1], op[2]

            if bisect.bisect_left(d, x + size - 1) == bisect.bisect_left(d, x):
                st.append("1")
            else:
                st.append("0")

    return "".join(st)

