struct Node {
  Node( int v ) : val{v} {}

  int val{ 0 };
  Node *next{ nullptr };
};


class MyLinkedList {
    std::size_t length{ 0 };
    Node *head{ nullptr };
public:
    /** Initialize your data structure here. */
    MyLinkedList() {}
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get( int index )
    {
        // std::cout << "get" << std::endl;
      if( index >= length )
          return -1;
    
        if( index == 0 )
            return head->val;
 
        auto cur = head;
        while( cur && index-- > 0 )
            cur = cur->next;
        
        return cur ? cur->val : -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead( int val )
    {
        // std::cout << "addAtHead" << std::endl;
        Node *node = new Node( val );
        if( head )
            node->next = head;
        
        head = node;        
        ++length;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail( int val )
    {
        // std::cout << "addAtTail" << std::endl;
        Node *node = new Node( val );
        if( !head ) {
            head = node;
             ++length;
            return;
        }
        
        auto cur = head;
        while( cur && cur->next )
            cur = cur->next;
        
        cur->next = node;
        ++length;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex( int index, int val )
    {
        // std::cout << "addAtIndex" << std::endl;
        if( !index ) {
            addAtHead( val );
        } else if( index == length ) {
            // std::cout << "here" << std::endl;
            addAtTail( val );
        } else if( index > length ) {
            return;
        } else {
            Node *node = new Node( val );
            auto cur = head;
            while( --index > 0 )
                cur = cur->next;
            
            node->next = cur->next;
            cur->next = node;
            ++length;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex( int index )
    {
        // std::cout << "delete" << std::endl;
        if( index < 0 || index >= length )
            return;
 
        if( !head || !length )
            return;
            
        if( !index ) {
            // std::cout << "here 1" << std::endl;
            head = head->next;
            --length;
            return;
        }

        // std::cout << "index = " << index << std::endl;
        // std::cout << "length = " << length << std::endl;
        // std::cout << "here 2" << std::endl;
        auto cur = head;
        Node *prev = nullptr;
        while( cur && index-- > 0 ) {
            prev = cur;
            // if( !cur )
            //     break;
            cur = cur->next;
        }
        
        if( cur && prev )
            prev->next = cur->next;
        --length;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
