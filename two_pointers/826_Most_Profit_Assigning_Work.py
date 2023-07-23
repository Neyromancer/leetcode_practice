"""
Link: https://leetcode.com/problems/most-profit-assigning-work/description/

Description:
You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs.

Examples:
1/
Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
Output: 100
Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
"""

class Solution:
    # TC: O(NlogN + MlogM), where N == len(difficulty) and M == len(worker)
    # SC: O(N), where N == len(difficulty)
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        profit_per_work: List[List[int]] = sorted(zip(difficulty, profit)) # O(N), where N == len(difficulty)

        result: int = 0
        max_profit: int = 0
        j: int = 0
        for ability in sorted(worker):
            while j < len(profit_per_work) and ability >= profit_per_work[j][0]:
                max_profit = max(max_profit, profit_per_work[j][1])
                j += 1

            result += max_profit

        return result
