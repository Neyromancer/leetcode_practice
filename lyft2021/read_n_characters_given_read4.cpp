/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n)
    {
        int read{ 0 };
        char buf4[ 5 ]{};
        int res = read4( buf4 );
        while( res && n > 0 ) {
            std::memcpy( buf + read, buf4, std::min( res, n ) );
            read += std::min( res, n );
            n -= res;
            std::memset( buf4, 0, 5 );
            res = read4( buf4 );
        }
        buf[ read ] = '\0';
        
        return read;
    }
};
