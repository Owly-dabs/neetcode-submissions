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
    TreeNode* invertTree(TreeNode* root) {
        // Base case: return nullptr if root is nullptr
        if (root == nullptr) return root;

        vector<TreeNode*> queue;
        int ind = 0;
        TreeNode* temp;
        queue.push_back(root);
        while (ind < queue.size()) {
            TreeNode* curr = queue[ind];
            // Check if curr node has children
            if (curr->left != nullptr && curr->right != nullptr) {
                // swap
                temp = curr->left;
                curr->left = curr->right;
                curr->right = temp;

                // add children to queue
                queue.push_back(curr->left);
                queue.push_back(curr->right);
            } else if (curr->left != nullptr) {
                //swap
                curr->right = curr->left;
                curr->left = nullptr;

                // add left child to queue
                queue.push_back(curr->right);
            } else if (curr->right != nullptr) {
                //swap
                curr->left = curr->right;
                curr->right = nullptr;

                // add right child to queue
                queue.push_back(curr->left);
            }
            
            ind++;
        }
        return root;
    }

};
