"""
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Examples:

1/
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

2/
Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

3/
Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

SC: O(N), N == len(s)
TC: O(1)
"""
def maxVowels(self, s: str, k: int) -> int:
    def is_vowel(ch: str) -> bool:
        return ch == "a" or ch == "e" or ch == "i" or \
               ch == "o" or ch == "u"

    res: int = 0
    left: int = 0
    cnt: int = 0
    for right in range(len(s)):
        if is_vowel(s[right]):
            cnt += 1
        
        if right - left + 1 == k:
            res = max(cnt, res)
            cnt -= 1 if is_vowel(s[left]) else 0
            left += 1
    return res

"""
    TC: O(N), where N == len(s)
    SC: O(1)
"""
def maxVowels(self, s: str, k: int) -> int:
    def is_vowel(ch: str) -> bool:
        return ch in "aeiou"

    res: int = 0
    cnt: int = 0
    for i in range(k):
        if is_vowel(s[i]):
            cnt += 1
    
    res = cnt
    for i in range(k, len(s)):
        cnt += 1 if is_vowel(s[i]) else 0
        cnt -= 1 if is_vowel(s[i - k]) else 0
        res = max(res, cnt)
    return res
