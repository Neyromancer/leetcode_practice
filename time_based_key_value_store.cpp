#include <map>
#include <string>
#include <unordered_store>

// space O( N ) N - get-method's calles
// time O( N ) N - get-method's calles
class TimeMap {
    std::unordered_map<std::string, std::map<int, std::string,std::greater<int>>> storage;
public:
    /** Initialize your data structure here. */
    TimeMap() {}
    
    void set(string key, string value, int timestamp)
    {
        auto &time_value = storage[ key ];
        time_value[ timestamp ] = value;
    }
    
    string get(string key, int timestamp)
    {
        const auto &time_value = storage[ key ];
        if( time_value.empty() )
            return {};
        
        if( timestamp >= ( *std::begin( time_value ) ).first )
            return ( *std::begin( time_value ) ).second;
        
        std::string res;
        for( auto it = std::begin( time_value ); it != std::end( time_value ); ++it ) {
            if( it->first <= timestamp ) {
                res = it->second;
                break;            
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
