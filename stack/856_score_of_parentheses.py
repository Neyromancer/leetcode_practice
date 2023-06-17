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
