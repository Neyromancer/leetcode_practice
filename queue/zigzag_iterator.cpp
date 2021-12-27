class ZigzagIterator {
    std::queue<int> storage;
public:
    // time O( max( sizeof( v1 ), sizeof( v2 ) ) )
    // space O( sizeof( v1 ) + sizeof( v2 ) )
    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        int i = 0;
        while( i < v1.size() || i < v2.size() ) {
            if( i < v1.size() )
                storage.push( v1[ i ] );

            if( i < v2.size() )
                storage.push( v2[ i ] );
            ++i;
        }
    }

    // time O( 1 )
    // space O( 1 )
    int next()
    {
        auto digit = storage.front();
        storage.pop();
        return digit;
    }

    // time O( 1 )
    // space O( 1 )
    bool hasNext()
    {
        return !storage.empty();
    }
};
