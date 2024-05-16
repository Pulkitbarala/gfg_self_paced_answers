class Solution:
    def solve(self, N, a):
        result = []
        i = 0

        while i < N:
            if a[i] != a[a[i] - 1]:
                a[a[i] - 1], a[i] = a[i], a[a[i] - 1]
            else:
                i += 1

        for i in range(N):
            if a[i] != i + 1:
                result.append(a[i])
                result.append(i + 1)
                break

        return result