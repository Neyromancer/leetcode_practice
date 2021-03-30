// time O( N ), N - size of sum of a, b and c
// space O( 1 )
class Solution {
public:
    string longestDiverseString(int a, int b, int c) 
    {
        int size = a + b + c;
        int cntA{ 0 };
        int cntB{ 0 };
        int cntC{ 0 };
        std::string res;
        for( int i = 0; i < size; ++i ) { // O( N )
            if( ( a >= b && a >= c && cntA != 2 ) || 
                ( cntB == 2 && a > 0 ) || 
                ( cntC == 2 && a > 0 ) ) {
                res.append( 1, 'a' ); // constant operation
                --a;
                ++cntA;
                cntB = 0;
                cntC = 0;
            } else if( ( c >= b && c >= a && cntC != 2 ) || 
                       ( cntB == 2 && c > 0 ) || 
                       ( cntA == 2 && c > 0 ) ) {
                res.append( 1, 'c' ); // constant
                --c;
                ++cntC;
                cntA = 0;
                cntB = 0;
            } else if( ( b >= c && b >= a && cntB != 2 ) || 
                       ( cntC == 2 && b > 0 ) || 
                       ( cntA == 2 && b > 0 ) ) {
                res.append( 1, 'b' ); // constant
                --b;
                ++cntB;
                cntA = 0;
                cntC = 0;
            }
      }
                      
    return res;
  }
};
