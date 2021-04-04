class Solution {
public:
    std::pair<int, int> get_min_max_days( const vector<int> &bloomDay )
    {
        int max_day{ INT_MIN };
        int min_day{ INT_MAX };
        for( int i = 0; i < bloomDay.size(); ++i ) {
            min_day = std::min( min_day, bloomDay[ i ] );
            max_day = std::max( max_day, bloomDay[ i ] );
        }
        
        return { min_day, max_day };
    }
    
    int minDays( vector<int>& bloomDay, int m, int k ) 
    {
        if( bloomDay.size() / k < m )
            return -1;

        auto[ min_day, max_day ] = get_min_max_days( bloomDay );
        while( min_day < max_day ) {
            int d = min_day + ( max_day - min_day ) / 2;
            int cnt{ 0 };
            int bouquets{ 0 };
            for( int i = 0; i < bloomDay.size(); ++i ) {
                if( bloomDay[ i ] > d ) {
                    cnt = 0;
                } else {
                    ++cnt;
                    if( cnt >= k ) {
                        ++bouquets;
                        cnt = 0;
                    }
                }
            }
            
            if( bouquets < m )
                min_day = d + 1;
            else
                max_day = d;
        }
        
        return min_day;
    }
};
