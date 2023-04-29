"""
Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.

Examples:

1/
Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).


2/
Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
Output: 6
Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.
"""

# TC: O(N), where N == len(arr)
# SC: O(1)
def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
    res: int = 0
    left: int = 0
    sum_range: int = 0

    for right in range(len(arr)):
        sum_range += arr[right]
        if right - left + 1 == k:
            avg: float = sum_range / k
            if avg >= threshold:
                res += 1
               
            sum_range -= arr[left]
            left += 1
     return res
