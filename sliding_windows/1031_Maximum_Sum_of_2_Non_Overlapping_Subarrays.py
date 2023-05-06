"""
Given an integer array nums and two integers firstLen and secondLen, return the maximum sum of elements in two non-overlapping subarrays with lengths firstLen and secondLen.

The array with length firstLen could occur before or after the array with length secondLen, but they have to be non-overlapping.

A subarray is a contiguous part of an array.

Examples:

1/
Input: nums = [0,6,5,2,2,5,1,9,4], firstLen = 1, secondLen = 2
Output: 20
Explanation: One choice of subarrays is [9] with length 1, and [6,5] with length 2.

2/
Input: nums = [3,8,1,3,2,1,8,9,0], firstLen = 3, secondLen = 2
Output: 29
Explanation: One choice of subarrays is [3,8,1] with length 3, and [8,9] with length 2.

3/
Input: nums = [2,1,5,6,0,9,5,0,3,8], firstLen = 4, secondLen = 3
Output: 31
Explanation: One choice of subarrays is [5,6,0,9] with length 4, and [0,3,8] with length 3.

TC: O(N), where N == len(nums)
SC: O(N), where N == len(nums)
"""

def maxSumTwoNoOverlap(self, nums: List[int], firstLen: int, secondLen: int) -> int: 
    prefixSumArray = [0] * (len(nums) + 1)
    for i in range(len(nums)):
        prefixSumArray[i + 1] = prefixSumArray[i] + nums[i]

    def range_max(nums: List[int], firstLen: int, secondLen: int) -> int:
        res: int = 0
        first_max_sum: int = 0
        for i in range(firstLen + secondLen, len(nums)):
            first_max_sum = max(first_max_sum, nums[i - secondLen] - nums[i - secondLen - firstLen])
            res = max(res, first_max_sum + nums[i] - nums[i - secondLen])
        return res
    
    return max(range_max(prefixSumArray, firstLen, secondLen), range_max(prefixSumArray, secondLen, firstLen))
