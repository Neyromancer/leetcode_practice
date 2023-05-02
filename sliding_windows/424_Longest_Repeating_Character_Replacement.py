"""
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Examples:

1/
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

2/
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
"""

class Solution:
    def __init__(self):
        self.cache: List[int] = [0] * 27
    """
        |
            |
        A A B C D A B B A
        0 1 2 3 4 5 6 7 8

        frequency: 1
        min_freq


        cache:
            A: 2
            B: 1
    """
    def calc_symbol_frequency(self):
        symbol_with_max_freq: int = 0
        max_freq: int = 0

        for i, n in enumerate(self.cache):
            if n > max_freq:
                max_freq = n
                symbol_with_max_freq = i

        frequency: int = 0
        for i, n in enumerate(self.cache):
            if not symbol_with_max_freq == i:
                frequency += n
        return frequency

    """
        TC: O(N), where N == len(s)
        SC: O(1)
    """
    def characterReplacement(self, s: str, k: int) -> int:
        res: int = 0
        left: int = 0
        for right in range(len(s)):
            self.cache[ord(s[right]) - 65] += 1

            while self.calc_symbol_frequency() > k:
                self.cache[ord(s[left]) - 65] -= 1
                left += 1
            
            res = max(res, right - left + 1)
        return res
