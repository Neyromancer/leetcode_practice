"""
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.

Examples:

1/
Input: s = "()"
Output: 1

2/
Input: s = "(())"
Output: 2

3/
Input: s = "()()"
Output: 2
"""

"""
Find a score of an overall string.

Opening parenthese means that we are going to the lower level. In code it means that we have to store the score of the current we counted so far before counting the score
of the deeper level.

Closing parenthese means that are going to the higher level. In code it means that we have to increase the score calculated at the current level by 2 with each higher level and the score from the current level which we calculated before started to go to the deeper level.

TC: O(N), where N == len(s)
SC: O(N), where N == len(s)
"""

def scoreOfParentheses(self, s: str) -> int:
    score: int = 0
    stack: List[int] = list()
    for ch in s:
        if ch == "(":
            stack.append(score) # O(1)
            score = 0
        elif ch == ")":
            score = stack.pop() + max(score * 2, 1) # O(1)
    return score


"""
Count the number of opening braces when we stumble on the 1st closing brances after openning braces it means that we reached the bottom
level of the sequence of braces, e.g like "((()))". When the bottom is reached it's score could be calculated as 2 power number of braces.
It is so becase we have the rule that each higher level has a score of the previous lower level multipled by 2, in other words 2 times the number of levels substracting the bottom level.

  TC: O(N), where N == len(s)
  SC: O(1)
"""

def scoreOfParentheses(self, s: str) -> int:
    braces: int = 0
    ans: int = 0

    for i, ch in enumerate(s):
        if ch == "(":
            braces += 1
        else:
            braces -= 1

            if s[i - 1] == "(":
                ans += 1 << braces
    return ans

"""
    TC: O(N * N), where N == len(s)
    SC O(N), where N == len(s)
"""
def scoreOfParentheses(self, s: str) -> int:
    return self.countScore(s, 0, len(s))

def countScore(self, s: str, i: int, j: int) -> int:
    bal: int = 0
    res: int = 0
    for k in range(i, j):
        bal += 1 if s[k] == "(" else -1
        if bal == 0:
            if k - i == 1:
                res += 1
            else:
                res += 2 * self.countScore(s, i + 1, k)
            i = k + 1
    return res
