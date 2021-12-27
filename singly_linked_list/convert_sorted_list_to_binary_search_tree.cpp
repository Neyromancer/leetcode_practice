class Solution {
public:
    // space O( log N )
    // time O( N log N )
    TreeNode* sortedListToBST(ListNode* head)
    {
        if( !head )
            return nullptr;

        auto fast = head;
        auto slow = head;
        ListNode* prev = nullptr;
        while( fast && fast->next ) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode( slow->val );
        if( prev )
            prev->next = nullptr;

        root->left = prev ? sortedListToBST(head) : nullptr;
        root->right = sortedListToBST(slow->next);
        return root;
    }
};

cass Solution {
public:
    // time O( N )
    // space O( N )
    std::vector<int> ll_to_vc( ListNode* head ) {
        std::vector<int> res;
        while( head ) {
            res.push_back( head->val );
            head = head->next;
        }
        return res;
    }

    // time O( N )
    // space O( N )
    TreeNode* to_tree( const std::vector<int>& vc, int l, int r ) {
        if( l >= vc.size() || r < 0 || l > r )
            return nullptr;
        
        int mid = l + ( r - l ) / 2;
        TreeNode* root = new TreeNode( vc[ mid ] );
        root->left = to_tree( vc, l, mid - 1 );
        root->right = to_tree( vc, mid + 1, r );
        return root;
    }
    
    TreeNode* to_tree( const std::vector<int>& vc ) {
        int l = 0;
        int r = static_cast<int>( vc.size() );
        return to_tree( vc, l, r );
    }

    // time O( N )
    // space O( N )
    TreeNode* sortedListToBST(ListNode* head)
    {
        if( !head )
            return nullptr;

        std::vector<int> list = ll_to_vc( head ); // time O( N ) and space O( N )
        return to_tree( list );
    }
};


