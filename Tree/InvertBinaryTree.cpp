/*
 * Invert a Binary Tree
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Date: 03/23/2020
 * Author: Wei Du
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        auto lft = invertTree(root->left);
        auto rht = invertTree(root->right);
        auto temp = root->left;
        root->left = root->right;
        root->right= temp;
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            auto left = invertTree(root->left);
            auto right = invertTree(root->right);
            std::swap(root->left, root->right);
            return root;
        }
        return nullptr;
    }
};
