"""
Link: https://leetcode.com/problems/boats-to-save-people/description/

You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

Example:
1/
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)

2/
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)

3/
Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)

TC: O(N logN), where N == len(people)
SC: O(logN), where N == len(popeple)
"""

class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        result: int = 0
        people.sort() # TC: O(N log N), where N == len(people)
        l: int = 0
        r: int = len(people) - 1
        while l <= r:
            if people[l] + people[r] <= limit:
                l += 1

            r -= 1
            result += 1
        return result
