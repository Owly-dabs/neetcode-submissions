# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        # Swap such that p.val <= q.val
        if p.val > q.val:
            temp = p
            p = q
            q = temp
        
        def traverse(node: TreeNode) -> TreeNode:
            if p.val <= node.val and node.val <= q.val:
                return node
            elif p.val <= node.val and q.val <= node.val:
                return traverse(node.left)
            elif node.val <= p.val and node.val <= q.val:
                return traverse(node.right)

        return traverse(root)