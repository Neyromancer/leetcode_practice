// time O( N * log M ) where N == nums.size(), M == q.size()
// space O( log M ), where M == q.size()
int thirdMax(vector<int>& nums)
{
  if( nums.empty() )
    return 0;
        
  std::set<int> q;
  for( auto &&n : nums ) {
    q.insert( n ); // O( log N ), where N == q.size()
    if( q.size() > 3 )
      q.erase( std::begin( q ) ); // O( 1 )
  }
        
  return q.size() == 3 ? *std::begin( q ) : *std::rbegin( q ); 
}

class Solution {
public:
    // space O( 1 )
    // time O( N ), where N == nums.size()
    int thirdMax( vector<int>& nums )
    {
        if( nums.empty() )
            return 0;
        
        auto nlimits = std::numeric_limits<std::int64_t>::max();
        int64_t m1 = nlimits;
        int64_t m2 = nlimits;
        int64_t m3 = nlimits;
        for( auto &&n : nums ) {
            if( m1 == nlimits ) {
                m1 = n;
            } else if( m1 < n ) {
                m3 = m2;
                m2 = m1;
                m1 = n;
            } else if( m1 > n ) {
                if( m2 == nlimits ) {
                    m2 = n;
                    continue;
                }
                
                if( m2 < n ) {
                    m3 = m2;
                    m2 = n;
                } else if( m2 > n ) {
                    if( m3 == nlimits || m3 < n )
                        m3 = n;
                }
            }
        }
        
        return m3 == nlimits ? m1 : m3;
    }
};

class Solution {
public:
    // space O( 1 )
    // time O( N ), where N == nums.size()
    int thirdMax(vector<int>& nums)
    {
        if( nums.empty() )
            return 0;
        
        auto nlimits = std::numeric_limits<int64_t>::min();
        int64_t m1 = nlimits;
        int64_t m2 = nlimits;
        int64_t m3 = nlimits;
        for( auto &&n : nums ) {
            if( n > m1 ) {
                m3 = m2;
                m2 = m1;
                m1 = n;
            } else if( n > m2 && n != m1 ){
                m3 = m2;
                m2 = n;
            } else if( n > m3 && n != m2 && n != m1 )
                m3 = n;
        }
        
        return m3 == nlimits ? m1 : m3;
        
    }
};
