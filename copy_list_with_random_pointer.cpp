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
