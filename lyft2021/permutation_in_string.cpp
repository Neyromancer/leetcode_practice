class Solution {
    std::array<int, 27> al{};
public:
    // time O( N ), where N == min( s1, s2 )
    // space O( 1 )
    bool checkInclusion( string s1, string s2 ) 
    {
        if( s1.size() > s2.size() )
            return false;

        for( auto ch : s1 )
            ++al[ ch - 'a'];
        
        int k = s1.size();
        for( int i = 0; i <= s2.size() - k; ++i ) {
            if( has_permutation( s2, i, k + i ) )
                return true;
        }
        
        return false;
    }
    
    bool has_permutation( std::string_view s, int l, int r )
    {
        std::array<int,27> al1{};
        for( int i = l; i < r; ++i )
            ++al1[ s[ i ] - 'a' ];
        
        for( int i = 0; i < al1.size(); ++i )
            if( al1[ i ] != al[ i ] )
                return false;
        return true;
    }
};

class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        if( s1.size() > s2.size() )
            return false;

        std::array<int, 27> al1{};
        for( auto ch : s1 )
            ++al1[ ch - 'a' ];
        
        int k = s1.size();
        std::array<int, 27> al2{};
        for( int i = 0; i < k; ++i )
            ++al2[ s2[ i ] - 'a' ];
        
        for( int i = k; i < s2.size(); ++i ) {
            if( are_included( al1, al2 ) )
                return true;
            
            --al2[ s2[ i - k ] - 'a' ];
            ++al2[ s2[ i ] - 'a' ];
        }
        
        if( are_included( al1, al2 ) )
            return true;
        
        return false;
    }
    
    template<std::size_t N = 27>
    bool are_included( const std::array<int,N> a1, 
                       const std::array<int,N> a2 )
    {
        for( int i = 0; i < a1.size(); ++i )
            if( a1[ i ] != a2[ i ] )
                return false;
        return true;
    }
};
