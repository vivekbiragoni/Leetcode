class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numMap = {}
        for i, num in enumerate(nums):
            compliment = target - num
            if compliment in numMap: 
                return [numMap[compliment], i]
            numMap[num] = i
        return [-1,-1]