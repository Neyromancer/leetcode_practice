class FreqStack {
    std::unordered_map<int, int> counter_storage;
    std::list<int> storage;
    int max_cnt{ 0 };
public:
    FreqStack() {}
    
    void push( int val )
    {
        ++counter_storage[ val ];
        max_cnt = std::max( max_cnt, counter_storage[ val ] );
        storage.push_back( val );
    }
    
    void recalc_max()
    {
        for( const auto &[val, cnt] : counter_storage )
            max_cnt = std::max( max_cnt, cnt );
    }
    
    int pop()
    {
        if( storage.empty() )
            return 0;
        
        int res{ 0 };
        for( auto it = storage.rbegin(); it != storage.rend(); ++it) {
            int val = *it;
            int &cnt = counter_storage[ *it ];
            if( cnt == max_cnt ) {
                res = *it;
                storage.erase( std::next( it ).base() );
                --cnt;
                max_cnt = 0;
                break;
            }
        }

        recalc_max();
        return res;
    }
};
