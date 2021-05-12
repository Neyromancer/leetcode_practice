/*
["MagicDictionary", "buildDict", "search", "search", "search", "search", "search", "search", "search", "search", "search"]
[[], [["a","b","ab"]], ["a"], ["b"], ["c"], ["d"], ["e"], ["f"], ["ab"], ["ba"], ["abc"]]
*/

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool is_word{ false };
};

class Trie {
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode();
    }
    
    // O( word.size() )
    void insert( std::string &&word )
    {
        auto current = root;
        for( char ch : word ) {
            if( !current->children.count( ch ) )
                current->children[ ch ] = new TrieNode(); // O( 1 )
            
            current = current->children[ ch ]; // O( 1 )
        }

        current->is_word = true;
    }
    
    // O( 27 * N^2 ), where N == word.size, 27 - letters in eng alphabet
    bool search( std::string word )
    {
        for( int i = 0; i < word.size(); ++i ) {
            for( char ch = 'a'; ch <= 'z'; ++ch ) {
                if( ch == word[ i ] ) // O( 1 )
                    continue;

                std::swap( word[ i ], ch ); // O( 1 )
                auto current = root;
                if( dfs( current, 0, word ) )
                    return true;

                std::swap( word[ i ], ch ); // O( 1 )
            }
        }

        return false;
    }
    
    // O( N ), N == word.size() 
    bool dfs( TrieNode *current, int i, const std::string &word )
    {
        if( !current )
            return false;
        
        if(  i >= word.size() && current->is_word )
            return true;
        
        if( i >= word.size() )
            return false;
        
        for( const auto &[ ch, node ] : current->children ) {
            if( ch == word[ i ] ) {
                if( dfs( node, i + 1, word ) )
                    return true;
            }
            
            continue;
        }
        
        return false;
    }
};

class MagicDictionary {
    Trie st;
public:
    /** Initialize your data structure here. */
    MagicDictionary(){}
    
    // O( N * M ), where N == longest word and M == dictionary size
    void buildDict(vector<string> dictionary)
    {
        for( auto &&word : dictionary )
            st.insert( std::move( word ) );
    }
    
    // time O( N^2 ), where N == searchWord
    // space O( N ), where N == searchWord
    bool search( string searchWord )
    {
        return st.search( searchWord );
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

struct TrieNode {
    std::unordered_map<char, TrieNode *> children;
    bool is_word{ false };
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
        
        cur->is_word = true;
    }
    
    bool search( std::string &&word )
    {
        return search( root, word, 0, false );
    }
    
    bool search( TrieNode *parent, const std::string &word, int i, bool is_ch_changed )
    {
        if( i < word.size() ) {
            if( parent->children.count( word[ i ] ) ) {
                if( search( parent->children[ word[ i ] ], word, i + 1, is_ch_changed ) )
                    return true;
            }
            
            if( !is_ch_changed ) {
                for( const auto &[ ch, node ] : parent->children ) {
                    if( ch != word[ i ] && search( node, word, i + 1, true ) )
                        return true;
                }
            }
            
            return false;
        }
        
        return is_ch_changed && parent->is_word;
    }
};
class MagicDictionary {
    Trie st;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {}
    
    void buildDict(vector<string> dictionary)
    {
        for( auto &&word : dictionary )
            st.insert( std::move( word ) );
    }
    
    bool search( string searchWord )
    {
        return st.search( std::move( searchWord ) );
    }
};

struct TrieNode {
    std::unordered_map<char, TrieNode *> children;
    bool is_word{ false };
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    // time O( word.size )
    // space O( word.size )
    void insert( std::string &&word )
    {
        auto current = root;
        for( auto ch : word ) {
            if( !current->children.count( ch ) ) // O( 1 )
                current->children[ ch ] = new TrieNode(); // O( 1 )
            
            current = current->children[ ch ]; // O( 1 )
        }

        current->is_word = true;
    }
    
    // time O( word.size )
    // space O( word.size )    
    bool search( std::string &&word )
    {
        return search( root, word, 0, 0 );
    }
    
    // time O( word.size )
    // space O( word.size )
    bool search( TrieNode *parent, const std::string &word, int index, int cnt )
    {
        if( cnt > 1 || index > word.size() )
            return false;
        
        if( index == word.size() )
            return parent->is_word && cnt == 1;
        
        for( const auto &[ ch, node ] : parent->children ) {
            if( search( node, word, index + 1, ( ch == word[ index ] ? cnt : cnt + 1 ) ) )
                return true;
        }
        
        return false;
    }
};

class MagicDictionary {
    Trie st;
    
public:
    /** Initialize your data structure here. */
    MagicDictionary() {}
    
    // time O( word.size * dictionary.size )
    // space O( word.size * dictionary.size )    
    void buildDict(vector<string> dictionary)
    {
        for( auto &&word : dictionary )
            st.insert( std::move( word ) );
    }

    // time O( word.size )
    // space O( word.size )    
    bool search(string searchWord)
    {
        return st.search( std::move( searchWord ) );
    }
};
