class HitCounter {
    std::list<int> st;
public:
    /** Initialize your data structure here. */
    HitCounter(){}
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    // time O( sizeof( st ) )
    void hit( int timestamp )
    {
        while( !st.empty() && st.front() <= timestamp - 300 )
            st.pop_front(); // O( 1 )
        
        st.push_back( timestamp );
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    // time O( sizeof( st ) )
    int getHits( int timestamp )
    {
        int cnt{ 0 };
        for( auto it = std::begin( st ); it != std::end( st ); ++it )
            if( *it >= timestamp - 300 + 1 )
                ++cnt;
        return cnt;
    }
};
