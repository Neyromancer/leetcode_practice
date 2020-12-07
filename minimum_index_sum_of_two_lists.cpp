#include <unordered_map>
#include <string>
#include <vector>

std::vector<std::string> findRestaurant( std::vector<std::string> &list1,
                                         std::vector<std::string> &list2 ) {
  if( list1.size() == 1 && list2.size() == list1.size() && list1[ 0 ] == list2[ 0 ] )
    return { list2[ 0 ] };

  std::unordered_map<std::string, int> storage1;
  for( int i = 0; i < list1.size(); ++i )
    storage1[ list1[ i ] ] = i;

  std::unordered_map<std::string, int> storage2;
  for( int i = 0; i < list2.size(); ++i )
    if( storage1.find( list2[ i ] ) != std::end( storage1 ) )
      storage2[ list2[ i ] ] = i + storage1[ list2[ i ] ];

  int least_val{ INT_MAX };
  for( const auto &el : storage2 )
    if( least_val > el.second )
      least_val = el.second;

  std::vector<std::string> res;
  for( const auto &el : storage2 )
    if( least_val == el.second )
      res.push_back( el.first );

  return res;
}
