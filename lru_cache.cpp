// space O( N^2 ), where N is number of get calls
// time for get() - constant
// time for put() - constant
class LRUCache {
  std::unordered_map<int, std::list<std::pair<int,int>>::iterator> m;
  std::list<int,int> l;
  int size{ 0 };
public:
  LRUCache( int capacity )
  {
    size = capacity;
  }

  int get( int key )
  {
     auto it = m.find( key );
     if( it == std::end( m ) )
       return -1;

     l.splice( std::begin( l ), l, m[ key ] );
     return m[ key ]->second;
  }

  void put( int key, int value )
  {
    auto it = m.find( key );
    if( it != std::end( m ) ) {
      m[ key ]->second = value;
      l.splice( std::begin( l ), l, m[ key ] );
    } else {
      l.push_back( { key, valye } );
      m[ key ] = std::begin( l );
      if( l.size() > size ) {
        m.erase( l.back().first );
        l.pop_back();
      }
    }
  }
};
