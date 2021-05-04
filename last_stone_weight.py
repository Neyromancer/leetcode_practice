class Solution:
    # time O( N log N ), where N is the size of list 
    # space O ( N ), where N is the size of list
    def lastStoneWeight(self, stones: List[int]) -> int:
        if not stones:
            return 0
        
        stones.sort( reverse=True ) # O( N log N ), where N is the size of list
        while len( stones ) > 1:
            n1 = stones.pop( 0 ) # O( N ), where N is the size of the list
            n2 = stones.pop( 0 ) # O( N ), where N is the size of the list
            
            val = min( n1, n2 ) # O( 1 )
            n1 -= val
            if n1:
                stones.append( n1 ) # O( 1 )
            
            n2 -= val
            if n2:
                stones.append( n2 ) # O( 1 )

            stones.sort( reverse=True ) # O( N log N ), where N is the size of list
                
        if not stones:
            return 0
        
        return stones.pop()
