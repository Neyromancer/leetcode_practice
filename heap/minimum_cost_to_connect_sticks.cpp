    // TC: O( N log N ), where N == sticks.size();
    // SC: O( N ), where N == sticks.size();
    int connectSticks(vector<int>& sticks) 
    {
        if( sticks.size() == 1 )
            return 0;

        std::priority_queue<int, std::vector<int>, decltype(std::greater<int>())> q{std::greater<int>(), sticks};
        
        int res{ 0 };
        while( q.size() > 1 ) {
            auto n1 = q.top(); // O( 1 )
            q.pop(); // O( log( sizeof( q ) ) )
            auto n2 = q.top(); // O( 1 )
            q.pop(); // O( log( sizeof( q ) ) )
            int tmp = n1 + n2;
            res += tmp;
            q.push( tmp ); // O( log( sizeof( q ) ) )
        }
        return res;
    }
