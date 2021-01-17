#include <set>
#include <vector>

std::vector<std::vector<int>> KClosest( std::vector<std::vector<int>> &points, int K ) {
  auto cmp = []( const std::pair<double, std::vector<int>> &el1,
                 const std::pair<double, std::vector<int>> &el2 ){
    return std::get<0>( el1 ) > std::get<0>( el2 );
  };

  std::multiset<std::pair<double, std::vector<int>>, decltype( cmp )> storage( cmp );
  for( int i = 0; i < points.size(); ++i ) {
    if( storage.size() < K ) {
      storage.insert( std::make_pair( std::sqrt( std::pow( points[ i ][ 0 ], 2 ) +
                                                 std::pow( points[ i ][ 1 ], 2 ) ),
                                      points[ i ] ) );
      continue;
    }

    auto it = std::begin( storage );
    auto num = std::sqrt( std::pow( points[ i ][ 0 ], 2 ) + std::pow( points[ i ][ 1 ], 2 ) );
    if( std::get<0>( *it ) > num ) {
      storage.erase( it );
      storage.insert( std::make_pair( num, points[ i ] );
    }
  }

  std::vector<std::vector<int>> res;
  res.reserve( storage.size() );
  for( auto &el : storage )
    res.push_back( el.second );

  return res;
}
