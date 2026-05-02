/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int dep = depth(root);
        if (dep==-1) return false;
        return true;
    }
    int depth(TreeNode* root) {
        if (root==nullptr) return 0;
        int lDep = depth(root->left);
        int rDep = depth(root->right);
        if (lDep == -1 || rDep == -1 || 
            lDep - rDep > 1 || lDep - rDep < -1) return -1;
        return 1 + max(lDep,rDep);
    }
};
