class Solution {
public:
    // time O( 26 x s2.size() )
    // space O( 1 )
    bool checkInclusion(string s1, string s2)
    {
        if( s1.size() > s2.size() ) // O( 1 )
            return false;

        std::array<int, 26> st{};
        for( auto ch : s1 ) // O( s1.size() )
            ++st[ ch - 'a' ]; // O( 1 )
        
        std::array<int, 26> goal{};
        for( int i = 0; i < s2.size(); ++i ) { // O( s2.size() )
            ++goal[ s2[ i ] - 'a' ]; // O( 1 )
            
            if( i >= s1.size() ) // O( 1 )
                --goal[ s2[ i - s1.size() ] - 'a' ]; // O( 1 )
            
            if( i >= s1.size() - 1 )
                if( goal == st ) // O( goal.size() == 26 )
                    return true;
        }
        
        return false;
    }
};

class Solution {
public:
    // time O( s2.size() ) as s2 is the longest
    // space O( 1 )
    bool checkInclusion(string s1, string s2) 
    {
        if( s1.size() > s2.size() ) // O( 1 )
            return false;
        
        std::array<int, 26> st{};
        for( auto ch : s1 ) // O( s1.size() )
            --st[ ch - 'a' ]; // O( 1 )
        
        int l{ 0 };
        for( int r = 0; r < s2.size(); ++r ) { // O( s2.size() )
            if( ++st[ s2[ r ] - 'a' ] > 0 ) { // O( 1 )
                while( --st[ s2[ l++ ] - 'a' ] != 0 ); // O( s2.size() )
            } else if( r - l + 1 == s1.size() )
                return true;
        }
        
        return false;
    }
};
