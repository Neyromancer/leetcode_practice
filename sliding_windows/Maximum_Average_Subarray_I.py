"""
You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

Examples:

1/
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

2/
Input: nums = [5], k = 1
Output: 5.00000
"""

# TC: O(N), where N == len(nums)
# SC: O(1)

def findMaxAverage(self, nums: List[int], k: int) -> float:
    res: float = min(nums)
    sum_range: int = 0
    left: int = 0
    for right in range(len(nums)):
        sum_range += nums[right]
        if right - left + 1 == k:
            avg: float = sum_range / k
            res = max(res, avg)

            sum_range -= nums[left]
            left += 1

    return res
