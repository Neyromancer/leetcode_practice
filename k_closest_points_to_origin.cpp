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

class Solution {
public:
    double calc_dist( const std::vector<int>& ptr ) {
        return std::sqrt( std::pow( ptr[ 0 ], 2 ) + std::pow( ptr[ 1 ], 2 ) );
    }

    // time O( N * k log k )
    // space O( k )
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
         auto cmp = []( const std::pair<double, std::vector<int>>& p1,
                        const std::pair<double, std::vector<int>>& p2 ) {
             return std::get<0>( p1 ) <= std::get<0>( p2 );
         };
        
        std::priority_queue<std::pair<double, std::vector<int>>, 
        std::vector<std::pair<double, std::vector<int>>>, decltype(cmp)> q(cmp);
        for( const auto& ptr : points ) {
            auto dist = calc_dist( ptr );
            q.push( std::make_pair( dist, ptr ) ); // O( k log k )
            if( q.size() > k )
                q.pop();// O( k log k )
        }
        
        std::vector<std::vector<int>> res;
        res.reserve( k );
        while( !q.empty() ) {
            auto node = q.top(); // O( k log k )
            res.push_back( std::move( std::get<1>( node ) ) ); // O( k log k )
            q.pop();
        }
        
        return res;
    }
};

class Solution {
public:
    double calc_dist( const std::vector<int>& ptr ) {
        return std::sqrt( std::pow( ptr[ 0 ], 2 ) + std::pow( ptr[ 1 ], 2 ) );
    }

    // time O( N log N )
    // space O( N )
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
         auto cmp = []( const std::pair<double, std::vector<int>>& p1,
                        const std::pair<double, std::vector<int>>& p2 ) {
             return std::get<0>( p1 ) <= std::get<0>( p2 );
         };

        std::vector<std::pair<double, std::vector<int>>> vc;
        vc.reserve( points.size() );
        for( const auto& ptr : points )
            vc.push_back( std::make_pair( calc_dist( ptr ), ptr ) );

        std::sort( std::begin( vc ), std::end( vc ), cmp );
        
        
        std::vector<std::vector<int>> res;
        res.reserve( k );
        for( int i = 0; i < k; ++i )
            res.push_back( std::move( std::get<1>( vc[ i ] ) ) );

        return res;
    }
};
