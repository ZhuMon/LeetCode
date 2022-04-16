import math


class Solution:
    def countBits(self, n: int) -> list[int]:
        output = [0] * (n+1)
        offset = 1
        for i in range(1, n+1):
            if offset*2 == i:
                offset = i
            output[i] = 1 + output[i-offset]

        return output


s = Solution()
print(s.countBits(2))
