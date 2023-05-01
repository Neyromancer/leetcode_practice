"""
Given a string s, find the length of the longest 
substring without repeating characters.

Examples:

1/
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

2/
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

3/
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

O(N), where N == len(s)
O(N), where N == len(s)
"""

def lengthOfLongestSubstring(self, s: str) -> int:
    cache: Set[int] = set()
    left: int = 0
    res: int = 0

    for right in range(len(s)):
        while s[right] in cache: # O(M), M == len(cache)
            cache.remove(s[left]) # O(1)
            left += 1

        length = right - left + 1
        res = max(res, length)
        cache.add(s[right]) # O(1)
    return res
