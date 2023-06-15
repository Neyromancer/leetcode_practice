"""
          |
    (()())(())(()(()))

    braces: (
    res: ()()

    TC: O(N), where N == len(s)
    SC: O(N), where N == len(s)
"""
def removeOuterParentheses(self, s: str) -> str:
    res: str = ""
    braces: List[str] = list()

    for ch in s:
        if ch == "(":
            if len(braces) > 0:
                res += ch
            braces.append(ch)
        else:
            if len(braces) > 1:
                res += ch
            braces.pop()
    return res

"""
    TC: O(N), where N == len(s)
    SC: O(1)
"""
def removeOuterParentheses(self, s: str) -> str:
    opened: int = 0
    res: str = ""
    for ch in s:
        if ch == "(":
            if opened > 0:
                res += ch # O(1)
            opened += 1
        else:
            if opened > 1:
                res += ch # O(1)
            opened -= 1
    return res
