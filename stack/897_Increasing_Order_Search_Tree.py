"""
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

Example:

1/ 
Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

2/
Input: root = [5,1,7]
Output: [1,null,5,null,7]
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        return self.__inorderTraversal(root)
    
    """
        TC: O(N log N), whre N == len(root)
        SC: O(N), where N == len(root)
    """
    def __inorderTraversal(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        
        left: TreeNode = self.__inorderTraversal(root.left)
        right: TreeNode = self.__inorderTraversal(root.right)

        node: TreeNode = left
        while node and node.right:
            node = node.right
        
        if node:
            node.right = root
        
        root.left = None
        root.right = right
        return left or root
