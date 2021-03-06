
// space O( Row x Column )
// time O( Row x Column )
class Solution {
    int current_color{ 0 };
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        current_color = image[ sr ][ sc ];
        
        if( current_color != newColor )
            flood_fill( image, sr, sc, newColor );
        
        return image;
    }
    
    void flood_fill( vector<vector<int>>& image, int sr, int sc, int new_color )
    {
        if( sr < 0 || sc < 0 || sr >= image.size() || sc >= image[ 0 ].size() )
            return;
        
        if( image[ sr ][ sc ] != current_color )
            return;
        
        image[ sr ][ sc ] = new_color;
        flood_fill( image, sr + 1, sc, new_color );
        flood_fill( image, sr - 1, sc, new_color );
        flood_fill( image, sr, sc + 1, new_color );
        flood_fill( image, sr, sc - 1, new_color );
    }
};
