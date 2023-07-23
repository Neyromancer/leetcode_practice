"""
Link: https://leetcode.com/problems/4sum/submissions/
Description:

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Examples:
1/
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

2/
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
"""

class Solution:
    # TC: O(N * N * N), where N == len(nums)
    # SC: O(NlogN), where N == len(nums)
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        res: List[int] = list()

        nums.sort() # TC: O(NlogN) SC: O(NlogN), where N == len(nums)
        res: List[int] = list()
        for i, el in enumerate(nums):
            if i and nums[i] == nums[i - 1]:
                continue

            for j in range(i + 1, len(nums)):
                if j != i + 1 and nums[j] == nums[j - 1]:
                    continue

                sum_ = el + nums[j]
                l: int = j + 1
                r: int = len(nums) - 1

                while l < r:
                    local_sum = sum_ + nums[l] + nums[r]

                    if local_sum == target:
                        res.append([el, nums[j], nums[l], nums[r]])

                        l += 1
                        while l < r and nums[l] == nums[l - 1]:
                            l += 1

                        r -= 1
                    elif local_sum > target:
                        r -= 1
                    else:
                        l += 1
        return res
