/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// space O( N ), where N - list`s size
// time O( N^2 ), where N - list's size
class Solution {
public:
    Node *build_list( const std::vector<Node *> &storage )
    {
        Node *head = storage.front();
        Node *list = head;
        for( int i = 1; i < storage.size(); ++i ) {
            list->next = storage[ i ];
            list = list->next;
        }
        
        return head;
    }
    
    std::vector<Node *> fill_storage( Node* head )
    {
        std::vector<Node *> res;
        while( head ) {
            res.push_back( new Node( head->val ) );
            head = head->next;
        }
        
        return res;
    }
    
    Node* copyRandomList(Node* head) {
        if( !head )
            return nullptr;
        
        std::vector<Node *> storage = fill_storage( head );
        int i = 0;
        auto current = head;
        while( current ) {
            auto node= head;
            int cnt{ 0 };
            while( node && current->random != node ) {
                ++cnt;
                node = node->next;
            }
            
            if( node )
                storage[ i ]->random = storage[ cnt ];
            
            current = current->next;
            ++i;
        }
        
        return build_list( storage );
    }
};

// space O( 1 )
// time O( N );
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if( !head )
            return head;
        
        Node *current = head;
        while( current ) {
            auto tmp = current->next;
            current->next = new Node( current->val, nullptr, nullptr );
            current->next->next = tmp;
            current = tmp;
        }
        
        current = head;
        while( current ) {
            if( current->next && current->random )
                current->next->random = current->random->next;
            
            current = current->next ? current->next->next : current->next;
        }
        
        Node *old_node = head;
        Node *new_node = head->next;
        Node *new_head = head->next;
        while( old_node && new_node ) {
            old_node->next = old_node->next ? old_node->next->next : old_node->next;
            new_node->next = new_node->next ? new_node->next->next : new_node->next;
            
            old_node = old_node->next;
            new_node = new_node->next;
        }
        
        return new_head;
    }
};

// time O( N )
// space O( N )
class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        std::unordered_map<Node *, Node *> storage;
        auto current = head;
        while( current ) {
            storage.insert( { current, new Node( current->val ) } );
            current = current->next;
        }
        
        Node dummy( 0 );
        current = &dummy;
        while( head ) {
            current->next = storage[ head ];
            current = current->next;
            current->random = head->random ? storage[ head->random ] : nullptr;
            head = head->next;
        }
        
        return dummy.next;
    }
};

// space O( 1 )
// time O( N ), where N - list size
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if( !head )
            return head;
        
        Node *l1 = nullptr;
        Node *l2 = nullptr;
        for( l1 = head; l1; l1 = l1->next ) {
            l2 = new Node( l1->val );
            l2->next = l1->random;
            l1->random = l2;
        }
        
        for( l1 = head; l1; l1 = l1->next ) {
            l2 = l1->random;
            l2->random = l2->next ? l2->next->random : nullptr;
        }
        
        Node *new_head = head->random;
        for( l1 = head; l1; l1 = l1->next ) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = l1->next ? l1->next->random : nullptr;
        }
        
        return new_head;
    }
};

// time O( N )
// space O( N^2 )
class Solution {
    std::unordered_map<Node*, Node*> storage;
public:
    Node* copyRandomList( Node* head )
    {
        if( !head )
            return nullptr;
        
        if( storage[ head ] )
            return storage[ head ];
        
        storage[ head ] = new Node( head->val );
        storage[ head ]->next = copyRandomList( head->next );
        storage[ head ]->random = copyRandomList( head->random );
        return storage[ head ];
    }
};
