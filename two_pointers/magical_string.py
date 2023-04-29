class Solution:
    # TC: O(N), where N == n
    # SC: O(N), where N == n

    def magicalString(self, n: int) -> int:
        if n <= 0:
            return 0

        if n <= 3:
            return 1

        array = [None] * (n + 1)
        array[0] = 1
        array[1] = 2
        array[2] = 2
        head = 2
        tail = 3
        num = 1
        res = 1
        while tail < n:
            for i in range(array[head]):
                array[tail] = num

                if tail < n and num == 1:
                    res += 1
                
                tail += 1
            
            num = 3 - num
            head += 1
        
        return res




