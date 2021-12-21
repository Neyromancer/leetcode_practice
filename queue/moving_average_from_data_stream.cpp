class MovingAverage {
    int limit{ 0 };
    std::queue<int> storage;
    int sum{ 0 };
public:
    MovingAverage(int size)
    {
        limit = size;
    }
    
    double next(int val)
    {
        storage.push( val );
        sum += val;
        if( storage.size() > limit ) {
            sum -= storage.front();
            storage.pop();
        }
        
        return static_cast<double>( sum ) / storage.size();
    }
};
