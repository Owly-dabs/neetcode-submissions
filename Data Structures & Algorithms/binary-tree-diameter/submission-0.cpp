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
    int res = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        int t = dfs(root, res);
        return res;
    }
private: 
    int dfs(TreeNode* root, int& res){
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        int leftHeight = dfs(root->left, res);
        int rightHeight = dfs(root->right, res);
        int possibleRes = leftHeight+rightHeight;
        if (possibleRes>res) res = possibleRes;
        return 1+max(leftHeight,rightHeight);
    }
};
