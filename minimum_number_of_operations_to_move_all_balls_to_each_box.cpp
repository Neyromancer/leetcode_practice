// space O( N ), where N - size of boxes
// time O( N ), where N - size of boxes
class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        std::vector<int> res( boxes.size() );
        int cnt{ 0 };
        for( int i = 0; i < boxes.size(); ++i ) {
            res[ i ] = cnt + ( i > 0 ? res[ i - 1 ] : 0 );
            if( boxes[ i ] == '1' )
                ++cnt;
        }
        
        cnt = 0;
        std::vector<int> tmp( boxes.size() );
        for( int i = boxes.size() - 1; i >= 0; --i ) {
            tmp[ i ] = cnt + ( ( i < tmp.size() - 1 ) ? tmp[ i + 1 ] : 0 );
            if( boxes[ i ] == '1' )
                ++cnt;
        }
        
        int i = 0;
        int size = res.size();
        while( i < size ) {
            res[ i ] += tmp[ i ];
            ++i;
        }
        
        return res;
    }
};

// space O( N ), N - boxes.size();
// time O( 1 )
class Solution {
public:
  std::vector<int> res( boxes.size() )
  {
    int cnt{ 0 };
    int val{ 0 };
    int sz = boxes.size();
    std::vector<int> res( sz );
    for( int i = 1; i < sz; ++i ) {
      if( boxes[ i - 1 ] == '1' )
        ++cnt;
      val += cnt;
      res[ i ] = val;
    }

    cnt = 0;
    val = 0;
    for( int i = sz - 2; i >= 0; --i ) {
      if( boxes[ i + 1 ] == '1' )
        ++cnt;
      val += cnt;
      res[ i ] += val;
    }

    return res;
  }
};
