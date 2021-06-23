class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        if( !rowIndex )
            return { 1 };
        
        auto row = getRow( rowIndex - 1 );
        std::vector<int> res( row.size() + 1 );
        for( std::size_t i = 0; i < row.size() - 1; ++i )
            res[ i + 1 ] = row[ i ] + row[ i + 1 ];
        
        res.front() = 1;
        res.back() = 1;
        return res;
    }
};

