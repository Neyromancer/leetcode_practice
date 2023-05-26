"""
Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

Examples:

1/
Input: nums = [1,0,1,0,1], goal = 2
Output: 4

2/
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
"""
"""
    TC: O(N), where N == len(nums)
    SC: O(N), where N == len(nums)
"""
def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
    cache: Dict[int, int] = {0: 1}
    res: int = 0
    sub_sum: int = 0
    for num in nums:
        sub_sum += num
        if sub_sum >= goal:
            res += cache[sub_sum - goal]
        
        if sub_sum not in cache:
            cache[sub_sum] = 0

        cache[sub_sum] += 1     # <-
    return res
