# Detail：
# Runtime: 511 ms
# Memory Usage: 16.2 MB
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n = len(nums)
        i,j,k = 0,n - 1,n - 1
        ans = [-1] * n
        while k >= 0:
            left = nums[i] ** 2
            right = nums[j] ** 2
            if left < right:
                ans[k] = right
                j -= 1
            else:
                ans[k] = left
                i += 1
            k -= 1
        return ans