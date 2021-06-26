class Solution {
public:
    /** 1. create connections
            
        
    
    */
    
    bool trust_noone( const std::unordered_map<int, std::vector<int>> &st, int p )
    {
        for( const auto [ person, connections ] : st ) {
            if( p == person )
                continue;

            for( int c : connections )
                if( p == c )
                    return false;
        }
        
        return true;
    }
    
    int findJudge(int n, vector<vector<int>>& trust)
    {
        if( n == 1 && trust.empty() )
            return 1;

        std::unordered_map<int, std::vector<int>> st;
        for( int i = 0; i < trust.size(); ++i )
            st[ trust[ i ][ 1 ] ].push_back( trust[ i ][ 0 ] );
        
        for( const auto &[ person, connections ] : st )
            if( connections.size() == n - 1 && trust_noone( st, person ) )
                return person;
        
        return -1;
    }
};

class Solution {
public:
    // time O( T + n )
    // space O( T ), where T == trust.size()
    int findJudge(int n, vector<vector<int>>& trust)
    {
        std::vector<int> connections( n + 1 );
        for( const auto &t : trust ) {
            --connections[ t[ 0 ] ];
            ++connections[ t[ 1 ] ];
        }
        
        for( int i = 1; i <= n; ++i )
            if( connections[ i ] == n - 1 )
                return i;
        
        return -1;
    }
};
