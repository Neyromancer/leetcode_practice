"""
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

Examples:

1/
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

2/
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".

3/
Input: s = "abc"
Output: 1
"""


# TC: O(N), where N == len(s)
# SC: O(1)

def numberOfSubstrings(self, s: str) -> int:
    res: int = 0
    left: int = 0
    cache = [0] * 3

    def are_all_chars_met(seq: List[int]):
        return seq[0] >= 1 and seq[1] >= 1 and seq[2] >= 1

    for right in range(len(s)):
        cache[ord(s[right]) - 97] += 1
        while are_all_chars_met(cache):
            res += len(s) - right
            cache[ord(s[left]) - 97] -= 1
            left += 1
    return res


# SC: O(1)
# TC: O(N), where N == len(s)
def numberOfSubstrings(self, s: str) -> int:
    cache: List[int] = [-1] * 3
    res: int = 0
    for i, ch in enumerate(s):
         cache[ord(ch) - 97] = i
         res += min(cache) + 1
    return res
