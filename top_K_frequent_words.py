class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        words_cnt = Counter( words )
        candidates = list( words_cnt.keys() )
        candidates.sort( key = lambda w: ( -words_cnt[ w ], w ) )
        return candidates[:k]
