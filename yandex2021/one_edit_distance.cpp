class Solution {
public:
    // time O( 1 )
    // space O( 1 )
    bool isOneEditDistance( const string &s, const string &t )
    {
        if( s.size() > t.size() )
            return isOneEditDistance( t, s );

        int ssz = s.size();
        int tsz = t.size();
        if( std::abs( ssz - tsz ) >= 2 )
            return false;
        
        if( s.size() == t.size() ) {
            int cnt{ 0 };
            for( int i = 0; i < s.size(); ++i )
                if( s[ i ] != t[ i ] )
                    ++cnt;
            
            return cnt == 1;
        }
        
        int j{ 0 };
        int i{ 0 };
        for( ; i < t.size(); ++i ) {
            if( j >= s.size() )
                break;
            
            if( s[ j ] == t[ i ] )
                ++j;
        }
        
        if( j >= s.size() && i >= t.size() - 1 )
            return true;
        
        return false;
    }
};
