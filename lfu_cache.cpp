#include <list>
#include <unordered_map>

/**
The key has to be
 - comparable with the equality function,
 - available as hash value,
 - copyable and moveable.

The value has to be
 - default constructable,
 - copyable and moveable.

**/

template <class Key, class Value>
class LFUCache {
    std::int64_t m_capacity{ 0 };
    std::int64_t m_min_frequency{ 0 };
    // key -> { value, key_frequency }
    std::unordered_map<Key, std::pair<Value, std::int64_t>> m_storage;
    // key -> key node in m_frequency_keys
    std::unordered_map<Key, std::list<Key>::iterator> m_key_links;
    // frequency -> list of keys
    std::unordered_map<std::int64_t, std::list<Key>>  m_frequency_keys;
public:
    LFUCache( int capacity ) : m_capacity{ capacity } {}
   
    // time O( 1 ) 
    Value get( Key key )
    {
        if( !m_storage.count( key ) )
          return {};

        auto &[ value, frequency ] = m_storage[ key ];
        m_frequency_keys[ frequency++ ].erase( m_key_links[ key ] );
        m_frequency_keys[ frequency ].push_back( key );
        m_key_links[ key ] = std::prev( std::end( m_frequency_keys[ frequency ] ) );

        if( m_frequency_keys[ m_min_frequency ].size() == 0 )
              m_min_frequency++;

        return value;        
    }
    
    // time O( 1 )
    void put( Key key, Value value )
    {
        if( m_capacity <= 0 )
          return;

        if( auto stored_val = get( key ); stored_val != Value{} ) {
            m_storage[ key ].first = value; // O( 1 )
            return;
        }

        if( m_storage.size() >= m_capacity )
        {
            m_storage.erase( m_frequency_keys[ m_min_frequency ].front() ); // O( 1 ) ?
            m_key_links.erase( m_frequency_keys[ m_min_frequency ].front() ); // O( 1 ) ?
            m_frequency_keys[ m_min_frequency ].pop_front(); // O( 1 ) ?
        }

        m_storage[ key ] = { value, 1 }; // O( 1 )
        m_frequency_keys[ 1 ].push_back( key ); // O( 1 )
        m_key_links[ key ] = std::prev( std::end( m_frequency_keys[ 1 ] ) ); // O( 1 )
        m_min_frequency = 1;
    }
};
