class Solution {
public:
    // time O( N )
    // space O( N )
    int shareCandies(vector<int>& candies, int k)
    {
        // 1. создать хэш-мапу, хранящую сколько раз каждый из вкусов встречается
        // 2. создать хэш-сет, чтобы хранить уникальные элементы
        // 3. выбрать ряд элементов размером k из candies уменьшив количество в соот-х
        // элементов в хэш-мапе.
        // 4. если элемент в хэш-мапе имеет 0-е значение удалить его их хэш-сета
        // 5. при сдвигании ряда элементов размером k впараво уменьшать кол-во элментов в хэш-мапе добавляемых справа
        // 6. увеличивать кол-во -//- при удалении их из ряда размером k. 
        // 7. при каждом сдвиге обновлять результат.
        
        std::unordered_map<int, int> uniq_candies;
        std::unordered_set<int> flavours;
        for( int i = 0; i < candies.size(); ++i ) {
            ++uniq_candies[ candies[ i ] ]; // O( 1 )
            flavours.insert( candies[ i ] ); // O( 1 )
        }
        
        for( int i = 0; i < k; ++i ) {
           --uniq_candies[ candies[ i ] ];  // O( 1 )
            if( !uniq_candies[ candies[ i ] ] ) // O( 1 )
                flavours.erase( candies[ i ] ); // O( 1 )
        }
        
        std::size_t uniq_flavors = flavours.size(); // O( 1 )
        for( int i = k; i < candies.size(); ++i ) {
            --uniq_candies[ candies[ i ] ]; // O( 1 )
            ++uniq_candies[ candies[ i - k ] ];
            flavours.insert( candies[ i - k ] );
            
            if( !uniq_candies[ candies[ i ] ] )
                flavours.erase( candies[ i ] );
            
           uniq_flavors = std::max( uniq_flavors, flavours.size() ); 
        }
        
        return uniq_flavors;
    }
};

class Solution {
public:
    int shareCandies(vector<int>& candies, int k)
    {
        std::array<int, 100001> uniq_flavours{};
        int res{ 0 };
        int cur_uniqs{ 0 };
        for( int i = k; i < candies.size(); ++i ) {
            if( !uniq_flavours[ candies[ i ] ]++ )
                res = ++cur_uniqs;
        }
        
        for( int i = k; i < candies.size(); ++i ) {
            if( !uniq_flavours[ candies[ i - k ] ]++ )
                ++cur_uniqs;
            
            if( !--uniq_flavours[ candies[ i ] ] )
                --cur_uniqs;
            
            res = std::max( res, cur_uniqs );
        }
        
        return res;
    }
};
