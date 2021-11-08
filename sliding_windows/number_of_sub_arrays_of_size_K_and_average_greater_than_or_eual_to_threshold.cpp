class Solution {
public:
    // space O( 1 )
    // time O( sizeof( arr ) )
    int numOfSubarrays(vector<int>& arr, int k, int threshold)
    {
        if( !k || arr.empty() )
            return 0;
        
        std::size_t sum{ 0 };
        int cnt{ 0 };
        for( int i = 0; i < arr.size(); ++i ) {
            sum += arr[ i ];
            if( i + 1 - k >= 0 ) {
                if( sum / k >= threshold )
                    ++cnt;
                
                sum -= arr[ i + 1 - k ];
            }
        }
        
        return cnt;
    }
}t;
