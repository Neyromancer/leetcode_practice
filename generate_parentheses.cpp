std::vector<std::string> generateParenthesis( int n )
{
  std::vector<std::string> ans;
  generate_all( ans, "", 0, 0, n );
  return ans;
}

void generate_all( std::vector<std::string> &ans, std::string cur, int open, int close, int max )
{
  if( cur.size() == max * 2 ) {
    ans.push_back( cur );
    return;
  }

  if( open < max )
    generate_all( ans, cur + "(", open + 1, close, max );

  if( close < max )
    generate_all( ans, cur + ")", open, close + 1, max );
}

std::vector<std::string> generateParenthesis( int n )
{
  if( n == 0 )
    return { "" };

  std::vector<std::string> ans;
  for( int c = 0; c < n; ++c ) {
    for( auto left : generateParenthesis( c ) )
      for( auto right : generateParenthesis( n - ( c + 1 ) ) )
        ans.push_back( "(" + left + ")" + right );
  }
  return ans;
}
