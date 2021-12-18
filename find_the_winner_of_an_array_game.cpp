// time O( sizeof( arr ) )
// space O( 1 )
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        k = k > arr.size() ? arr.size() : k;
        int winner{ arr.front() };
        int wins{ 0 };
        for( int i = 1; i < arr.size(); ++i ) {
            if( winner < arr[ i ] ) {
                winner = arr[ i ];
                wins = 1;
            } else {
                ++wins;
            }
            
            if( wins == k )
                break;
        }
        
        return winner;
    }
};
