# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # BFS 
        res = []
        if root is None:
            return res
        to_explore = [root]
        next_level = []
        curr_level = []
        # Starting at root
        while to_explore != []:
            # add children to to_explore queue
            curr = to_explore.pop()
            if curr.left:
                next_level.insert(0, curr.left)
            if curr.right:
                next_level.insert(0, curr.right)
            # add root to result
            curr_level.append(curr.val)
            if to_explore == []:
                res.append(curr_level[:])
                to_explore = next_level[:]
                next_level = []
                curr_level = []
        return res