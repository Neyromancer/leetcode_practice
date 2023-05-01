"""
There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. You are given an integer array customers of length n where customers[i] is the number of the customer that enters the store at the start of the ith minute and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.

Examples:

1/
Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
Output: 16
Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

2/
Input: customers = [1], grumpy = [0], minutes = 1
Output: 1

TC: O(N), where N == len(customers)
SC: O(1)
"""

def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
    res: int = 0

    for i, n in enumerate(customers):
        if not grumpy[i]:
            res += n
            customers[i] = 0

    satisfaction: int = 0
    local_satisfaction: int = 0
    left: int = 0
    for right in range(len(customers)):
        if right - left + 1 > minutes:
            local_satisfaction -= customers[left]
            left += 1

        local_satisfaction += customers[right]
        satisfaction = max(local_satisfaction, satisfaction)
    
    return satisfaction + res
