class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        std::vector<std::string> tmp;
        n =  n * 2;
        generate_parenthesis( n, tmp, "" );
        std::vector<std::string> res;
        for( const auto &seq : tmp )
            if( is_valid( seq ) )
                res.push_back( seq );
        
        return res;
    }
    
    bool is_valid( std::string_view seq )
    {
        int cnt{ 0 };
        for( char ch : seq ) {
            if( ch == '(' )
                ++cnt;
            else
                --cnt;
            
            if( cnt < 0 )
                return false;
        }
        
        return cnt == 0;
    }
    
    void generate_parenthesis( int n, std::vector<std::string> &vc, std::string seq )
        {
            if( n <= 0 ) {
                vc.push_back( seq );
                return;
            }
            
            generate_parenthesis( n - 1, vc, seq + '(' );
            generate_parenthesis( n - 1, vc, seq + ')' );
        }  
};

class Solution {
public:
    vector<string> generateParenthesis( int n )
    {
        std::vector<std::string> res;
        generate_parenthesis( n, 0, 0, res, "" );
        return res;
    }
    
    void generate_parenthesis( int n, int l, int r, std::vector<std::string> &res, std::string cur )
    {
        if( n * 2 == cur.size() ) {
            res.push_back( cur );
            return;
        }
        
        if( l < n ) {
            cur.push_back( '(' );
            generate_parenthesis( n, l + 1, r, res, cur );
            cur.pop_back();
        }
        
        if( r < l ) {
            cur.push_back( ')' );
            generate_parenthesis( n, l, r + 1, res, cur );
            cur.pop_back();
        }
    }
};
