"""
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

Examples:

1/
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


2/
Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
Output: 10
Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
"""


# SC: O(1)
# TC: O(N), where N == len(nums)
def longestOnes(self, nums: List[int], k: int) -> int:
    flipped: int = 0
    left: int = 0
    res: int = 0
    for right in range(len(nums)):
        if nums[right] == 0:
            flipped += 1

        if flipped > k:
            while flipped > k:
                if nums[left] == 0:
                    flipped -= 1
                left += 1
        
        res = max(res, right - left + 1)
    return res

# TC: O(N), where N == len(nums)
# SC: O(1)
def longestOnes(self, nums: List[int], k: int) -> int:
    left: int = 0
    for right in range(len(nums)):
        k -= 1 - nums[right]
        if k < 0:
            k += 1 - nums[left]
            left += 1
    return right - left + 1
