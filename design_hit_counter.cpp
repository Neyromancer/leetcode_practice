/***
["HitCounter","hit","hit","getHits"]
[[],[10000],[10001],[10000]]
["HitCounter","hit","hit","hit","getHits","hit","getHits","getHits"]
[[],[1],[2],[3],[4],[300],[300],[301]]
["HitCounter","hit","hit","hit","getHits","hit","getHits","getHits"]
[[],[1],[2],[3],[4],[300],[300],[305]]
["HitCounter","hit","hit","hit","getHits","hit","getHits","getHits"]
[[],[1],[2],[3],[4],[300],[300],[10001]]
["HitCounter","hit","hit","hit","getHits","hit","getHits","hit","getHits"]
[[],[1],[2],[3],[4],[300],[300],[10000],[10000]]
["HitCounter","hit","hit","hit","getHits","hit","getHits","hit","hit","getHits"]
[[],[1],[2],[3],[4],[300],[300],[10000],[10001],[10000]]
["HitCounter","hit","hit","hit","getHits","hit","getHits","hit","hit","getHits"]
[[],[1],[2],[3],[4],[300],[300],[10000],[10001],[10001]]
["HitCounter","hit","hit","hit","getHits","getHits","getHits","getHits","getHits","hit","getHits"]
[[],[2],[3],[4],[300],[301],[302],[303],[304],[501],[600]]
*/

// space O( number of hit calls )
// 
class HitCounter {
    std::queue<int> storage;
public:
    /** Initialize your data structure here. */
    HitCounter() {}
    
    // time O( 1 ) - constant
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) 
    {
        storage.push( timestamp );
    }
    
    // time O( in the number of previous hits ), linear 
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp)
    {
        while( !storage.empty() && timestamp - storage.front() >= 300 )
            storage.pop();
        
        return storage.size();
    }
};
