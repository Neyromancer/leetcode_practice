class MyCircularQueue {
    int head{ -1 };
    int back{ -1 };
    int size{ 0 };
    std::vector<int> storage;
public:
    MyCircularQueue(int k)
    {
        size = k;
        storage.resize( k );
    }
    
    bool enQueue( int value )
    {
        if( isFull() )
            return false;
        
        if( isEmpty() )
            head = 0;
        
        back = ( back + 1 ) % size;
        storage[ back ] = value;
        return true;
    }
    
    bool deQueue()
    {
        if( isEmpty() )
            return false;
        
        if( head == back ) {
            head = -1;
            back = -1;
            return true;
        }
        
        head = ( head + 1 ) % size;
        return true;
    }
    
    int Front()
    {
        if( isEmpty() )
            return -1;
        return storage[ head ];
    }
    
    int Rear()
    {
        if( isEmpty() )
            return -1;
        return storage[ back ];
    }
    
    bool isEmpty()
    {
        return head == -1;
    }
    
    bool isFull()
    {
        return ( ( back + 1 ) % size ) == head;
    }
};
