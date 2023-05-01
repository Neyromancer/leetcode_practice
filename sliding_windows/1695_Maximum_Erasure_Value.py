"""
You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

Return the maximum score you can get by erasing exactly one subarray.

An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

Examples:

1/
Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

2/
Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].


TC: O(N), where N == len(nums)
SC: O(N), where N == len(nums)
"""

def maximumUniqueSubarray(self, nums: List[int]) -> int:
    left: int = 0
    sm: int = 0
    res: int = 0
    cache: Set[int] = set()

    for right in range(len(nums)):
        while nums[right] in cache: # O(M), where M == len(cache)
            sm -= nums[left] # O(1)
            cache.remove(nums[left]) # O(1)
            left += 1

        sm += nums[right] # O(1)
        cache.add(nums[right]) # O(1)
        res = max(res, sm)
    return res
