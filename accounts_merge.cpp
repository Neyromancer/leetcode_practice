/*
[["John","johnsmith@mail.com","john_newyork@mail.com"],
             |
["John","johnsmith@mail.com","john00@mail.com"],

["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]

mail_to_id
johnsmith@mail.com : 0
john_newyork@mail.com : 1


mail_to_name
johnsmith@mail.com : John
john_newyork@mail.com : John

parent:
v   1 1 2 3 4 5
i   0 1 2 3 4 5
*/

class Solution {
    class UnionFind {
        std::vector<int> parent;
    public:
        UnionFind()
        {
            parent.resize( 10001 );
            for( int i = 0; i < parent.size(); ++i )
                parent[ i ] = i;
        }
        
        int find( int x ) //
        {
            if (parent[x] != x) 
                x = find( parent[x] );
            return x;
        }
        
        void unite( int id1, int id2 ) //
        {   
            int pid1 = find( id1 ); //
            int pid2 = find( id2 ); //
            if( id1 == id2 )
                return;

            parent[ pid1 ] = pid2;
        }
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        std::unordered_map<std::string, int> mail_to_id;
        std::unordered_map<std::string, std::string> mail_to_name;
        int id{ 1 }; // 2
        UnionFind uf;
        for( auto account : accounts ) {
            for( int i = 1; i < account.size(); ++i ) { // 1
                mail_to_name[ account[ i ] ] = account[ 0 ];
                auto &val = mail_to_id[ account[ i ] ];
                if( !val )
                    val = id++;

                uf.unite( mail_to_id[ account[ 1 ] ], mail_to_id[ account[ i ] ] ); // 0, 1
            }
        }
        
        std::unordered_map<int, std::vector<std::string>> id_to_emails;
        for( const auto &entry : mail_to_id ) {
            int index = uf.find( entry.second );
            auto &emails = id_to_emails[ index ];
            emails.push_back( entry.first );
        }
        
        std::vector<std::vector<std::string>> res;
        for( auto &entry : id_to_emails ) {
            std::vector<std::string> tmp;
            // for( int i = 1; i < entry.second.size(); ++i )
            //     tmp.push_back( entry.second[ i ] );
            tmp.insert( std::end( tmp ), std::begin( entry.second ), std::end( entry.second ) );
            std::sort( std::begin( tmp ), std::end( tmp ) );
            tmp.insert( std::begin( tmp ), mail_to_name[ entry.second[ 0 ] ] );
            res.push_back( tmp );
        }
        
        return res;
    }
};
