class Solution {
public:
    // time O( N * M ), where N == queries.size(), M == longest word in queries
    // space O( queries.size() )
    vector<bool> camelMatch(vector<string>& queries, string pattern) 
    {
        std::vector<bool> res( queries.size() );
        int i{ 0 };
        for( const auto &query : queries ) {
            int qid = 0;
            int pid = 0;
            while( qid < query.size() ) {
                if( pid < pattern.size() && query[ qid ] == pattern[ pid ] ) {
                    ++qid;
                    ++pid;
                } else {
                    if( is_upper( query[ qid ] ) ) // O( 1 )
                        break;
                    else
                        ++qid;
                }
            }


            if( pid >= pattern.size() && qid >= query.size() )
                res[ i ] = true; // O( 1 )
            ++i;
        }
        
        return res;
    }
    
    bool is_upper( char ch )
    {
        return ch >= 'A' && ch <= 'Z';
    }
};

class Solution {
public:
    // time O( N * M ), where N == queries.size(), M == longest word in queries
    // space O( queries.size() )
    vector<bool> camelMatch(vector<string>& queries, string pattern) 
    {
        std::vector<bool> res( queries.size() );
        int i{ 0 };
        for( const auto &query : queries )
            res[ i++ ] = match( query, pattern );
        
        return res;
    }
    
    bool match( const std::string &query, const std::string &pattern )
    {
        int j = 0;
        for( int i = 0; i < query.size(); ++i ) {
            if( j < pattern.size() && pattern[ j ] == query[ i ] ) {
                ++j;
            } else if( is_upper( query[ i ] ) ) {
                return false;
            }
        }
        
        return j >= pattern.size();
    }
    
    bool is_upper( char ch )
    {
        return ch >= 'A' && ch <= 'Z';
    }
};

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool is_end{ false };
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert( std::string &&word )
    {
        auto cur = root;
        for( auto ch : word ) {
            if( !cur->children.count( ch ) )
                cur->children[ ch ] = new TrieNode();
            
            cur = cur->children[ ch ];
        }

        cur->is_end = true;
    }
    
    bool search( std::string &&word )
    {
        auto cur = root;
        for( auto ch : word ) {
            if( !cur->children.count( ch ) && std::isupper( ch ) )
                return false;
            
            if( cur->children.count( ch ) )
                cur = cur->children[ ch ];
        }
        
        return cur->is_end;
    }
};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) 
    {
        Trie trie;
        trie.insert( std::move( pattern ) );
        std::vector<bool> res( queries.size() );
        int i = 0;
        for( auto &&query : queries )
            res[ i++ ] = trie.search( std::move( query ) );
        return res;
    }
};
