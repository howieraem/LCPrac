def find_no_of_splits(s: str):
    ans = 0
    # res = []
    visited_primes = set()

    def backtrack(substr): #, path):
        if not substr:
            nonlocal ans
            ans += 1
            # res.append(path[:])
            return

        for i in range(len(substr)):
            number = int(substr[0:i + 1])
            if number in visited_primes or is_prime(number):
                visited_primes.add(number)
                # path.append(number)
                backtrack(substr[i + 1:]) #, path)
                # path.pop()

    backtrack(s) #, [])

    return ans


def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if not (n & 1):   # n % 2 == 0
        return False
    for i in range(5, n // 2 + 1, 2):
        if not n % i:
            return False
    return True
