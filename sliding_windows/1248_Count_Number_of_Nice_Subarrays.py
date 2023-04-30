"""
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.


Examples:

1/
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

2/
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There is no odd numbers in the array.

3/
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16

TC: O(N), where N == len(nums)
SC: O(1)

1. first we are looking for a subarray which satisfies the requirements
2. when the array is found we mark it by setting the number of subarrays eq to 1
3. then we need to make sure that we will not count this array again and we do this by
   moving left index
4. moving left index solves another problem, i.e. counting all possible subarrays which include
   odd numbers found so far and even numbers which could also form required subarray
5. because we are moving left index only by one step we are sure that any time there is up to one
   odd number missed.
"""

def numberOfSubarrays(self, nums: List[int], k: int) -> int:
    left: int = 0
    odds: int = 0
    res: int = 0
    subarrays: int = 0

    def is_odd(num: int) -> bool:
        return not num % 2 == 0

    for right in range(len(nums)):
        if is_odd(nums[right]):
            odds += 1
            if odds >= k:
                subarrays = 1
                while not is_odd(nums[left]):
                    subarrays += 1
                    left += 1
                left += 1
                res += subarrays
        elif odds >= k:
            res += subarrays
    return res


"""
    1. at first -1 index is added because it helps to count the subarray by iteslf and the difference
       between the 1st index under odd number and till -1 it is all even numbers which build all possible
       subarrays with subarray which is built from required number of odd numbers.

       TC: O(N), where N == len(nums) 
       SC: O(k), k is k

"""
def numberOfSubarrays(self, nums: List[int], k: int) -> int:
    cache = []
    cache.append(-1)
    res: int = 0

    def is_odd(num: int) -> bool:
        return num % 2 == 1

    for right in range(len(nums)):
        if is_odd(nums[right]):
            cache.append(right)

        if len(cache) > k + 1:
            cache.pop(0)
        
        if len(cache) == k + 1:
            res += cache[1] - cache[0]
    return res
