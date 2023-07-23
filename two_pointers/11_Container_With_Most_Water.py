"""
Link: https://leetcode.com/problems/container-with-most-water/description/

Description:

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Examples:
1/
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

2/
Input: height = [1,1]
Output: 1
"""

class Solution:
    # TC: O(N), where N == len(height)
    # SC: O(1)
    def maxArea(self, height: List[int]) -> int:
        l: int = 0
        r: int = len(height) - 1
        volume: int = 0
        while l < r:
            volume = max(volume, (r - l) * min(height[l], height[r]))

            if height[l] >= height[r]:
                r -= 1
            else:
                l += 1
        return volume
