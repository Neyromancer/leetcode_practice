"""
A string is a valid parentheses string (denoted VPS) if it meets one of the following:

It is an empty string "", or a single character not equal to "(" or ")",
It can be written as AB (A concatenated with B), where A and B are VPS's, or
It can be written as (A), where A is a VPS.
We can similarly define the nesting depth depth(S) of any VPS S as follows:

depth("") = 0
depth(C) = 0, where C is a string with a single character not equal to "(" or ")".
depth(A + B) = max(depth(A), depth(B)), where A and B are VPS's.
depth("(" + A + ")") = 1 + depth(A), where A is a VPS.
For example, "", "()()", and "()(()())" are VPS's (with nesting depths 0, 1, and 2), and ")(" and "(()" are not VPS's.

Given a VPS represented as string s, return the nesting depth of s.


Examples:

1/
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3

2/
Input: s = "(1)+((2))+(((3)))"
Output: 3

  TC: O(N), where N == len(N)
  SC: O(1)
"""

def maxDepth(self, s: str) -> int:
    cnt: int = 0
    res: int = 0

    for brace in s:
        if brace == "(":
            cnt += 1
            res = max(cnt, res)
        elif brace == ")":
            cnt -= 1
    return res


"""
                                    |
    ( ( ) ( ( ( ) ( ( ) )   )  )  )
    0 1 2 3 4 5 6 7 8 9 10 11 12 13

    cache: ((
    res: 0, 2, 4, 5, 5, 5, 5, 5
    local_depth: 2, 4, 5, 4, 3, 2, 1

    TC: O(N), where N == len(s)
    SC: O(N), where N == len(s)
"""
def maxDepth(self, s: str) -> int:
    cache: List[str] = list()
    res: int = 0
    for ch in s:
        if ch == "(":
            cache.append(ch) # O(1)
        elif ch == ")":
            local_depth = len(cache) # O(1)
            res = max(local_depth, res) # O(1)
            cache.pop() # O(1)
    return res
