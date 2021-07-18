class LRUCache {
    int m_capacity{ 0 };
    std::list<std::pair<int,int>> m_recently_used;
    std::unordered_map<int,decltype( std::begin( m_recently_used ) )> m_positions;
public:
    LRUCache(int capacity)
    {
        m_capacity = capacity;
    }
    
    // time O( 1 )
    // space O( 1 )
    int get( int key )
    {
        if( !m_positions.count( key ) ) // O( 1 )
            return -1;
        
        auto node = m_positions[ key ]; // O( 1 )
        int val = node->second;
        m_positions.erase( key ); // O( 1 )
        m_recently_used.erase( node ); // O( 1 )
        m_recently_used.push_front( std::make_pair( key, val ) ); // O( 1 )
        m_positions[ key ] = std::begin( m_recently_used ); // O( 1 )
        
        return val;
    }
    
    // time O( 1 )
    // space O( 1 )
    void put( int key, int value )
    {
        if( m_positions.count( key ) ) {
            auto node = m_positions[ key ]; // O( 1 )
            m_recently_used.erase( node ); // O( 1 )
            m_positions.erase( key ); // O( 1 )
        } else if( m_recently_used.size() == m_capacity ) {
            auto node = m_recently_used.back(); // O( 1 )
            m_positions.erase( node.first ); // O( 1 )
            m_recently_used.pop_back(); // O( 1 )
        }
        
        m_recently_used.push_front( std::make_pair( key, value ) ); // O( 1 )
        m_positions[ key ] = std::begin( m_recently_used ); // O( 1 )
    }
};
