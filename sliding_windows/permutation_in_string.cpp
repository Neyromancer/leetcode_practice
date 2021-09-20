class Solution {
public:
    // time O( sizeof( s2 ) + sizeof( s1 ) )
    // space O( 1 )
    bool checkInclusion( string s1, string s2 )
    {
        if( s1.size() > s2.size() )
            return false;
        
        std::array<int, 27> arr1{};
        std::array<int, 27> arr2{};
        for( int i = 0; i < s1.size(); ++i ) {
            ++arr1[ s1[ i ] - 'a' ];
            ++arr2[ s2[ i ] - 'a' ];
        }
        
        if( arr1 == arr2 )
            return true;
        
        for( int i = s1.size(); i < s2.size(); ++i ) {
            --arr2[ s2[ i - s1.size() ] - 'a' ];
            ++arr2[ s2[ i ] - 'a' ];
            
            if( arr2 == arr1 )
                return true;
        }
        
        return false;
    }
};
