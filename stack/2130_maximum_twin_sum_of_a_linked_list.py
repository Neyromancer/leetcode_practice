"""
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

Examples:

1/
Input: head = [5,4,2,1]
Output: 6

2/
Input: head = [4,2,2,3]
Output: 7

3/
Input: head = [1,100000]
Output: 100001
"""

# TC: O(N), where N == len(head)
# SC: O(1)
def __find_mid_node(self, head: Optional[ListNode]) -> Optional[ListNode]:
    current = head
    next = head.next

    while next and next.next:
        current = current.next
        next = next.next.next

    next = current.next
    current.next = None
    return next

def __reverese(self, head: Optional[ListNode]) -> Optional[ListNode]:
    if not head:
        return None

    cur_node: Optional[ListNode] = head
    prev_node: Optional[ListNode] = None

    while cur_node:
        tmp_node = cur_node.next
        cur_node.next = prev_node
        prev_node = cur_node
        cur_node = tmp_node

    return prev_node


def pairSum(self, head: Optional[ListNode]) -> int:
    if not head:
        return 0

    mid_node = self.__find_mid_node(head)
    second_head = self.__reverese(mid_node)

    res: int = 0
    while head and second_head:
        res = max(res, head.val + second_head.val)
        head = head.next
        second_head = second_head.next
    return res


# TC: O(N), where N = len(head)
# SC: O(N), where N = len(head)
def pairSum(self, head: Optional[ListNode]) -> int:
    cur_node: Optinoal[ListNode] = head
    storage: List[ListNode] = list()

    while cur_node:
        storage.append(cur_node)
        cur_node = cur_node.next
    
    res: int = 0
    while head:
        res = max(res, storage.pop().val + head.val)
        head = head.next
    return res
