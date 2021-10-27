class Solution {
public:
    // time O( 1 )
    // space O( 1 )
    bool is_contained( const std::vector<std::vector<int>> &st, int n ) {
        return st[ 0 ][ 0 ] == n || st[ 1 ][ 0 ] == n;
    }
    
    // time O( 1 )
    // space O( 1 )
    int index( const std::vector<std::vector<int>> &st ) {
        return ( st[ 0 ][ 1 ] >= st[ 1 ][ 1 ] ? st[ 1 ][ 1 ] : st[ 0 ][ 1 ] ) + 1;
    }
    
    // time O( 1 )
    // space O( 1 )
    void add( std::vector<std::vector<int>>& st, int n, int index ) {
        if( st[0][0] == n ) {
            st[0][1] = index;
            return;
        }
        
        if( st[1][0] == n ) {
            st[1][1] = index;
            return;
        }
        
        if( st[ 0 ][ 1 ] >= st[ 1 ][ 1 ] ) {
            st[ 1 ][ 0 ] = n;
            st[ 1 ][ 1 ] = index;
        } else {
            st[ 0 ][ 0 ] = n;
            st[ 0 ][ 1 ] = index;            
        }
    }
    
    // time O( sizeof( fruits ) )
    // space O( 1 )
    int totalFruit(vector<int>& fruits) {
        if( fruits.size() <= 1 ) // O( 1 )
            return fruits.size(); // O( 1 )
        
        std::vector<std::vector<int>> st( 2, {-1, -1} );
        int len{ 0 };
        int l{ 0 };
        for( int r = 0; r < fruits.size(); ++r ) {
            if( !is_contained( st, fruits[ r ] ) ) // O( 1 )
                l = index( st ); // O( 1 )
            
            add( st, fruits[ r ], r ); // O( 1 )
            len = std::max( len, r - l + 1 ); //O( 1 )
        }
        return len;
    }
};

class Solution {
public:
    // time O( sizeof( fruits ) )
    // space O( 1 )
    int totalFruit(vector<int>& fruits)
    {
        if( fruits.size() <= 1 )
             return fruits.size();
        
        int basket1{ -1 };
        int basket2{ -1 };
        int l{ 0 };
        int r{ 0 };
        int len{ 0 };
        for(; r < fruits.size(); ++r ) {
            if( basket1 == -1 ) {
                basket1 = fruits[ r ];
                continue;
            }
            
            if( basket1 == fruits[ r ] )
                continue;
            
            if( basket2 == -1 ) {
                basket2 = fruits[ r ];
                continue;
            }
            
            if( basket2 == fruits[ r ] )
                continue;
            
            len = std::max( len, r - l );
            l = r - 1;
            while( l >= 1 && fruits[ l ] == fruits[ l - 1 ] )
                --l;
            
            basket1 = fruits[ l ];
            basket2 = fruits[ r ];
        }
        
        len = std::max( len, r - l );
        return len;
    }
};
