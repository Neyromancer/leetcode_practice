"""
Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

Examples:

1/
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

2/
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

3/
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

TC: O(N), where N == len(nums)
SC: O(1)
"""

def longestSubarray(self, nums: List[int]) -> int:
    is_0_met: bool = False
    cnt_0s: int = 0
    cnt_1s: int = 0
    left: int = 0
    res: int = 0

    for right in range(len(nums)):
        if nums[right] == 0:
            cnt_0s += 1
            is_0_met = True
        else:
            cnt_1s += 1

        while cnt_0s > 1:
            if nums[left] == 0:
                cnt_0s -= 1
            else:
                cnt_1s -= 1
            left += 1
        
        res = max(res, cnt_1s)
    return res if is_0_met else res - 1

"""

TC: O(N), where N == len(nums)
SC: O(1)
"""
def longestSubarray(self, nums: List[int]) -> int:
    left: int = 0
    available_0s: int = 1
    for right in range(len(nums)):
        if nums[right] == 0:
            available_0s -= 1

        if available_0s < 0:
            available_0s += 1 if nums[left] == 0 else 0
            left += 1

    return right - left
