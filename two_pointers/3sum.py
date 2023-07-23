"""
Link: https://leetcode.com/problems/3sum/

Description:
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Examples:
1/
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

2/
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

3/
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
"""


class Solution:
    # TC: O(N * N), where N == len(nums)
    # SC: O(NlogN), where N == len(nums)
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res: List[List[int]] = list()
        nums = sorted(nums) # TC: O(NlogN), SC: O(NlogN), where N == len(nums)
        for i, el in enumerate(nums): # O(N), where N == len(nums)
            if i and nums[i] == nums[i - 1]:
                continue
            
            tmp = self.__find(nums, i, el)
            if len(tmp) > 0:
                res += tmp  # TC: O(1), SC: O(1)
        return res
    
    # TC: O(N), where N == len(nums)
    # SC: O(1)
    def __find(self, nums: List[int], i: int, target: int) -> List[int]:
        l: int = i + 1
        r: int = len(nums) - 1
        res: List[List[int]] = list()
        while l < r:
            s: int = nums[l] + nums[r]
            if s + target == 0:
                res.append([nums[i], nums[l], nums[r]]) # TC: O(1), SC: O(1)
                l += 1
                while l and l < len(nums) and nums[l] == nums[l - 1]:
                    l += 1

                r -= 1
                while r and nums[r] == nums[r + 1]:
                    r -= 1
                
                if l == len(nums) or r < 0:
                    return res

            elif s + target > 0:
                r -= 1
            else:
                l += 1
        return res
