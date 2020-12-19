#include <cstdlib>
#include <vector>
#include <iostream>

void print( const std::vector<std::vector<int>> &vc ) {
  for( const auto &el : vc ) {
    for( auto ell : el )
      std::cout << ell << " ";
    std::cout << std::endl;
  }
}

std::vector<std::vector<int>> generateMatrix( int n ) {
  std::vector<std::vector<int>> res( n, std::vector<int>( n ) );

  print( res );

  int cnt{ 0 };
  int num{ 1 };
  while( cnt < n ) {
    for( int i = cnt; i < n - cnt; ++i ) {
      if( res[ cnt ][ i ] )
        break;
      else
        res[ cnt ][ i ] = num++;
    }

    for( int j = cnt + 1; j < n - cnt; ++j ) {
      if( res[ j ][ n - cnt - 1 ] )
        break;
      else
        res[ j ][ n - cnt - 1 ] = num++;
    }

    for( int i = n - ( cnt + 2 ); i >= cnt; --i ) {
      if( res[ n - cnt - 1 ][ i ] )
        break;
      else
        res[ n - cnt - 1 ][ i ] = num++;
    }

    for( int j = n - ( cnt + 2 ); j > cnt; --j ) {
      if( res[ j ][ cnt ] )
        break;
      else
        res[ j ][ cnt ] = num++;
    }

    ++cnt;
  }

  return res;
}

int main( void ) {  
  print( generateMatrix( 1 ) );
  std::cout << "=====================" << std::endl;

  print( generateMatrix( 3 ) );
  std::cout << "=====================" << std::endl;

  print( generateMatrix( 4 ) );
  std::cout << "=====================" << std::endl;

  print( generateMatrix( 5 ) );
  std::cout << "=====================" << std::endl;

  print( generateMatrix( 10 ) );
  std::cout << "=====================" << std::endl;

  return EXIT_SUCCESS;
}
