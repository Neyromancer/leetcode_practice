// iterative solution
class Solution {
public:
    // TC: O( N ), N == std::max({a,b,c})
    // SC: O( N ), N == std::max({a,b,c})
    int maximumScore(int a, int b, int c) {
        int score{ 0 };
        std::priority_queue<int> q;
        if( a )
            q.push( a );
        
        if( b )
            q.push( b );
        
        if( c )
            q.push( c );
        
        while( q.size() > 1 ) {
            int n1 = q.top();
            q.pop();
            int n2 = q.top();
            q.pop();
            ++score;
            if( n1 - 1 )
                q.push( n1 - 1 );
            
            if( n2 - 1 )
                q.push( n2 - 1 );
        }
        
        return score;
    }
};

// recursive solution
class Solution {
public:
    // TC: O( N ), N == std::max({a,b,c})
    // SC: O( N ), N == std::max({a,b,c})
    int maximumScore(int a, int b, int c) {
        if( a < b )
            return maximumScore( b, a, c );
        
        if( c > b )
            return maximumScore( a, c, b );
        
        return !b ? 0 : 1 + maximumScore( a - 1, b - 1, c );
    }
};
