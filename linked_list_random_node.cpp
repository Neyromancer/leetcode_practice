#include <random>
#include <vector>

class Solution {
  std::vector<int> storage;

public:
  Solution( ListNode *head ) {
    while( head != nullptr ) {
      storage.push_back( head->val );
      head = head->next;
    }
  }

  int getRandom() {
    std::random_device rd;
    std::mt19937 gen( rd() );
    std::uniform_int_distribution<> distrib( 1, storage.size() - 1 );
    return storage[ distrib( gen ) ];
  }

};
