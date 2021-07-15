class Solution {
public:
    // time O( N ), where N == sizeof s2 
    // space O( 1 )
    bool checkInclusion( string s1, string s2 )
    {
        if( s1.size() > s2.size() )
            return false;

        std::array<int, 27> al1{};
        for( auto ch : s1 )
            ++al1[ ch - 'a' ];
        
        int sz1 = s1.size();
        std::array<int, 27> al2{};
        for( int i = 0; i < sz1; ++i )
            ++al2[ s2[ i ] - 'a' ];
        
        if( al2 == al1 )
            return true;

        for( int i = sz1; i < s2.size(); ++i ) {
            ++al2[ s2[ i ] - 'a' ];
            --al2[ s2[ i - sz1 ] - 'a' ];

            if( al2 == al1 )
                return true;
        }

        return false;
    }
};


