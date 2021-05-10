/**
["Trie","insert","search","search","startsWith","insert","search"]
[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]
*/

// time O( N ), where N is the size of the word
// space O( key length )
struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool is_word{ false };
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }
    
    // O( N ), where N == word.size()
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        auto current = root;
        for( auto ch : word ) {
            if( !current->children.count( ch ) ) { // O( 1 )
                current->children[ ch ] = new TrieNode(); // O( 1 )
                // current->is_word = false;
            }
            
            current = current->children[ ch ]; // O( 1 )
        }
        current->is_word = true;
    }
    
    // O( N ), where N == word.size()
    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        auto current = root;
        for( auto ch : word ) {
            if( !current->children.count( ch ) ) // O( 1 )
                return false;
            
            current = current->children[ ch ]; // O( 1 )
        }

        return current->is_word;
    }
    
    // O( N ), where N == prefix.size()
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        auto current = root;
        for( auto ch : prefix ) {
            if( !current->children.count( ch ) ) // O( 1 )
                return false;
            
            current = current->children[ ch ]; // O( 1 )
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
