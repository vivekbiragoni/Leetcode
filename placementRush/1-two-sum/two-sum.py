class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_map = {}
        for i, num in enumerate(nums):
            complmnt = target - num
            if complmnt in num_map:
                return [num_map[complmnt], i]
            num_map[num] = i
        return []