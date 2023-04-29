"""
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Examples:

1/
Input: nums = [1,2,3,1], k = 3
Output: true

2/
Input: nums = [1,0,1,1], k = 1
Output: true

3/
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
"""

# SC: O(N), where N == len(nums) 
# TC: O(N), where N == len(nums)
def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
    cache: Dict[int, int] = {}
    left: int = 0

    for right in range(len(nums)):
        if nums[right] in cache:
            cache[nums[right]] += 1
        else:
            cache[nums[right]] = 1

        if right - left > k:
            cache[nums[left]] -= 1
            left += 1

        if cache[nums[right]] >= 2:
           return True

    return False

# SC: O(N), where N == len(nums) 
# TC: O(N), where N == len(nums)
def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
    cache: Dict[int, int] = {}

    for i, num in enumerate(nums):
        if num in cache and i - cache[num] <= k:
            return True
            
        cache[num] = i
    return False
