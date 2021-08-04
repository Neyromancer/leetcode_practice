class ZigzagIterator {
    std::vector<int> m_v1;
    std::vector<int> m_v2;
    int m_i1{ 0 };
    int m_i2{ 0 };
    bool is_1st{ true };
public:
    // time O( N + M ), N == sizeof( v1 ),M ==  sizeof( v2 )
    // space O( N + M ), N == sizeof( v1 ), M == sizeof( v2 )
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        m_v1 = v1;
        m_v2 = v2;
    }

    // time O( 1 )
    // space O( 1 )
    int next()
    {
        if( !hasNext() )
            return std::numeric_limits<int>::max();
        
        if( m_i1 < m_v1.size() && is_1st )
            is_1st = true;
        else if( m_i1 >= m_v1.size() )
            is_1st = false;
        else if( m_i2 >= m_v2.size() )
            is_1st = true;

        if( m_i1 < m_v1.size() && is_1st ) {
            is_1st = false;
            return m_v1[ m_i1++ ];  
        } else if( m_i2 < m_v2.size() ) {
            is_1st = true;
            return m_v2[ m_i2++ ];            
        }
        
        return std::numeric_limits<int>::max();
    }

    // time O( 1 )
    // space O( 1 )
    bool hasNext()
    {
        return m_i1 < m_v1.size() ||
               m_i2 < m_v2.size();
    }
};

/**
[1,2]
[3,4,5,6]
[1]
[]
[]
[1]
[1,2,4]
[5,6,7]
[1,2,4,8]
[5,6,7]
[1,2,4]
[5,6,7,9]
[1,2]
[]
[1,2,3]
[]
[]
[1,2,3]
[]
[1,2]

*/
class ZigzagIterator {
    std::vector<std::vector<int>> m_v;
    std::queue<int> q;
public:
    // time O( N + M ), N == sizeof( v1 ),M ==  sizeof( v2 )
    // space O( N + M ), N == sizeof( v1 ), M == sizeof( v2 )
    ZigzagIterator( vector<int>& v1, vector<int>& v2 )
    {
        if( !v1.empty() )
            m_v.push_back( v1 );
        if( !v2.empty() )
            m_v.push_back( v2 );
        
        std::size_t i = 0;
        bool has_elements{ true };
        while( has_elements ) {
            has_elements = false;
            for( const auto &el : m_v ) {
                if( i < el.size() ) {
                    has_elements = true;
                    q.push( el[ i ] );
                }
            }
            ++i;
        }
    }

    // time O( 1 )
    // space O( 1 )
    int next()
    {
        auto node = q.front();
        q.pop();
        return node;
    }

    // time O( 1 )
    // space O( 1 )
    bool hasNext()
    {
        return !q.empty();
    }
};

class ZigzagIterator {
    std::vector<std::vector<int>> m_v;
    int available{ 0 };
    int output{ 0 };
    int x{ 0 };
    int y{ 0 };
public:
    // time O( N + M ), where N == v1.size, M == v2.size
    // space O( N + M ), where N == v1.size, M == v2.size
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        if( !v1.empty() )
            m_v.push_back( v1 );
        
        if( !v2.empty() )
            m_v.push_back( v2 );
        
        for( const auto &vc : m_v )
            available += vc.size();
    }
    // time O( N ), N == m_v.size()
    // time O( 1 ) 
    int next()
    {
        int index{ 0 };
        int res = std::numeric_limits<int>::min();
        while( index < m_v.size() ) {
            if( x < m_v[ y ].size() ) {
                res = m_v[ y ][ x ];
                ++output;
            }
            
            y = ++y % m_v.size();
            if( !y )
                ++x;
            
            if( res != std::numeric_limits<int>::min() )
                return res;
            
            ++index;
        }
        
        return res;
    }

    // time O( 1 )
    // space O( 1 )
    bool hasNext()
    {
        return output < available;
    }
};

/**
[1,2]
[3,4,5,6]
[1]
[]
[]
[1]
[1,2,4]
[5,6,7]
[1,2,4,8]
[5,6,7]
[1,2,4]
[5,6,7,9]
[1,2]
[]
[1,2,3]
[]
[]
[1,2,3]
[]
[1,2]
[1,2]
[3,4,5,6]
[1]
[]
*/
class ZigzagIterator {
    std::queue<std::pair<std::vector<int>::iterator,std::vector<int>::iterator>> q;
public:
    // time O( std::max( v1.size, v2.size ) )
    // space O( 1 )
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        if( !v1.empty() )
            q.push( std::make_pair( std::begin( v1 ), std::end( v1 ) ) );

        if( !v2.empty() )
            q.push( std::make_pair( std::begin( v2 ), std::end( v2 ) ) );
    }

    // time O( 1 )
    // space O( 1 )
    bool hasNext()
    {
        return !q.empty();
    }

    // time O( 1 )
    // space O( 1 )
    int next()
    {
        auto [ begin, end ] = q.front();
        q.pop();
        int res = *( begin++ );
        if( begin != end )
            q.push( std::make_pair( begin, end ) );
        
        return res;
    }
};

class ZigzagIterator {
    std::queue<int> q;
public:
    // time O( std::max( v1.size, v2.size ) )
    // space O( sizeof( v1 ) + sizeof( v2 ) )
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        int i{ 0 };
        int j{ 0 };
        while( i < v1.size() || j < v2.size() ) {
            if( i < v1.size() )
                q.push( v1[ i++ ] );
            
            if( j < v2.size() )
                q.push( v2[ j++ ] );
        }
    }
    
    
    // time O( 1 )
    // space O( 1 )
    bool hasNext()
    {
        return !q.empty();
    }

    // time O( 1 )
    // space O( 1 )
    int next()
    {
        auto node = q.front();
        q.pop();
        return node;
    }
};
