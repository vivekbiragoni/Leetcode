class Solution:
    def maxArea(self, height: List[int]) -> int:
        maxi = 0
        j = len(height) -1
        i = 0
        while(i<j):
            area = min(height[i], height[j]) * (j - i)
            if area > maxi:
                maxi = area
            if (height[i]<height[j]):
                i = i+1
            else:
                j = j-1
        return maxi