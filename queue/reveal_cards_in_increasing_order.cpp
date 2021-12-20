class Solution {
public:
    // time O( sizeof( deck ) * log( sizeof( deck ) ) )
    // space O( sizeof( deck ) )
    vector<int> deckRevealedIncreasing(vector<int>& deck)
    {
        std::vector<int> res;
        res.resize( deck.size() );
        std::queue<int> q;
        for( int i = 0; i < deck.size(); ++i )
            q.push( i );

        std::sort( std::begin( deck ), std::end( deck ) );
        int i{ 0 };
        while( !q.empty() ) {
            auto index = q.front();
            q.pop();
            if( !q.empty() ) {
                q.push( q.front() );
                q.pop();
            }
            
            res[ index ] = deck[ i++ ];
            
        }

        return res;
    }
};
