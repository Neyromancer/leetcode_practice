#include <vector>

std::vector<std::vector<int>> restoreMatrix( std::vector<int>& rowSum, std::vector<int>& colSum ) {
  auto col_sz = colSum.size();
  auto row_sz = rowSum.size();
  std::vector<std::vector<int>> res( row_sz, std::vector<int>( col_sz ) );
  int i = 0;
  int j = 0;
  while( i < row_sz && j < col_sz ) {
    auto val = std::min( rowSum[ i ], colSum[ j ] );
    res[ i ][ j ] = val;
    rowSum[ i ] -= val;
    colSum[ j ] -= val;
    if( rowSum[ i ] == 0 ) {
      ++i;
    } else {
      ++j;
    }
  }
        
  return res;
}
