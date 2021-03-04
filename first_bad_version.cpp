// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// space O( 1 )
// time O( log N )
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        int ans = 0;
        while( l <= r ) {
            int mid = l + ( r - l ) / 2;
            if( isBadVersion( mid ) ) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return ans;
    }
};
