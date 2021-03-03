#include <map>
#include <vector>

// space O( N )
// time O( log N )
class TopVotedCandidate {
    // победитель ко времени
    std::map<int,int> time_to_winner;
    std::vector<int> times;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& _times) {
        // кол-во голосов каждого из кандидатов
        times = _times;
        std::unordered_map<int,int> votes_per_person;
        ++votes_per_person[ persons[ 0 ] ];
        time_to_winner[ times[ 0 ] ] = persons[ 0 ];
        for( int i = 1; i < times.size(); ++i ) {
            auto &person_votes = votes_per_person[ persons[ i ] ];
            time_to_winner[ times[ i ] ] = ( ++person_votes >=
                                            votes_per_person[ time_to_winner[ times[ i - 1 ] ] ] ) ?
                persons[ i ] : time_to_winner[ times[ i - 1 ] ];
        }
    }

    // 0, 5, 10, 15, 20, 25, 30 
    // 3
    int q(int t) {
        int l = 0;
        int r = times.size() - 1;
        int diff = std::abs( times[ r ] - t );
        while( l <= r ) {
            int mid = l + ( r - l ) / 2;
            if( times[ mid ] == t )
                return time_to_winner[ times[ mid ] ];
            
            if( times[ mid ] > t ) {
                r = mid - 1;
            } else if( times[ mid ] < t ) {
                l = mid + 1;
            }
        }
        
        return time_to_winner[ times[ r ] ];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
