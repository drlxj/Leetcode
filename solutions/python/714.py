class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            pivot = int((left + right) / 2)
            if target > nums[pivot]:
                left = pivot + 1
            elif target < nums[pivot]:
                right = pivot - 1
            else:
                return pivot
        return -1
