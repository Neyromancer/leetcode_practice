cass Solution {
public:
    // time O( N ), where N == asteroids.size
    // space O( 1 ), where N == asteroids.size
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        if( asteroids.empty() )
            return {};
        
        std::stack<int> st;
        // O( N ), where N == asteroid.size
        for( int i = 0; i < asteroids.size(); ++i ) {
            if( st.empty() ) {
                st.push( asteroids[ i ] );
            } else {
                auto a1 = st.top(); // O( 1 )
                auto a2 = asteroids[ i ]; // O( 1 )
                // O( N ), where N == st.size
                while( !st.empty() && are_colliding( a1, a2 ) ) {
                    st.pop(); // O( 1 )
                    a2 = collide( a1, a2 ); // O( 1 )
                    a1 = st.empty() ? 0 : st.top(); // O( 1 )
                }
                
                if( a2 )
                    st.push( a2 ); // O( 1 )
            }
        }
        
        std::vector<int> res( st.size() );
        // O( N ), where N == res.size
        for( int i = 0; i < res.size(); ++i ) {
            res[ i ] = st.top(); // O( 1 )
            st.pop(); // O( 1 )
        }
        
        // O( N ), where N == res.size
        std::reverse( std::begin( res ), std::end( res ) ); 
        
        return res;
    }
    
    bool are_colliding( int a1, int a2 )
    {
        return( a1 > 0 && a2 < 0 );
    }
    
    int collide( int a1 , int a2 )
    {
        if( std::abs( a1 ) > std::abs( a2 ) )
            return a1;
        else if( std::abs( a1 ) < std::abs( a2 ) )
            return a2;
        
        return 0;
    }
};
