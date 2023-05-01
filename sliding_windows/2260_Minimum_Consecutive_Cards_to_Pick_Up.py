"""
You are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.

Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.


Examples:

1/
Input: cards = [3,4,2,3,4,7]
Output: 4
Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.

2/
Input: cards = [1,0,5,3]
Output: -1
Explanation: There is no way to pick up a set of consecutive cards that contain a pair of matching cards.

TC: O(N), where N == len(cards)
SC: SC(N), where N == len(cards)
"""

def minimumCardPickup(self, cards: List[int]) -> int:
    cache: Dict[int, int] = {}

    res: int = sys.maxsize * 2 + 1
    for i, n in enumerate(cards): # O(N), where N == len(cards)
        if n in cache:
            res = min(res, i - cache[n] + 1) # O(1)
        
        cache[n] = i # O(1)
    return -1 if res == sys.maxsize * 2 + 1 else res
