class Solution {
public:
    // time O( sizeof( customers ) )
    // space O( 1 )
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int satisfied{ 0 };
        for( std::size_t i = 0; i < grumpy.size(); ++i ) {
            if( !grumpy[ i ] )
                satisfied += customers[ i ];
        }
        
        for( int i = 0; i < minutes; ++i ) {
            if( grumpy[ i ] )
                satisfied += customers[ i ];            
        }
        
        int max_satisfied = satisfied;
        for( std::size_t i = minutes; i < grumpy.size(); ++i ) {
            if( grumpy[ i ] )
                satisfied += customers[ i ];
            
            if( grumpy[ i - minutes ] )
                satisfied -= customers[ i - minutes ];
            
            max_satisfied = std::max( max_satisfied, satisfied );
        }
        
        return max_satisfied;
    }
};

class Solution {
public:
    // space O( sizeof( customers ) )
    // time O( 1 )
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
    {
        int satisfied{ 0 };
        for( std::size_t i = 0; i < customers.size(); ++i ) {
            if( !grumpy[ i ] )
                satisfied += customers[ i ]; // O( 1 )
        }
        
        std::deque<int> q;
        int max_satisfied = satisfied;
        for( std::size_t i = 0; i < customers.size(); ++i ) {
            q.push_back( customers[ i ] ); // O( 1 )
            if( grumpy[ i ] )
                satisfied += q.back(); // O( 1 )
            
            if( q.size() > minutes ) {
                if( grumpy[ i - minutes ] )
                    satisfied -= q.front(); // O( 1 )
                q.pop_front(); // O( 1 )
            }
            
            max_satisfied = std::max( max_satisfied, satisfied );
        }
        
        return max_satisfied;
    }
};
