/* Given the root of a binary tree, then value v and depth d, you need to add a
 * row of nodes with value v at the given depth d. The root node is at depth 1. */

/* The adding rule is: given a positive integer depth d, for each NOT null tree
 * nodes N in depth d-1, create two tree nodes with value v as N's left subtree
 * root and right subtree root. And N's original left subtree should be the left
 * subtree of the new left subtree root, its original right subtree should be
 * the right subtree of the new right subtree root. If depth d is 1 that means
 * there is no depth d-1 at all, then create a tree node with value v as the new
 * root of the whole original tree, and the original tree is the new root's left
 * subtree. */

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(root) {
            if(d==1) {
                root = new TreeNode(v, root, nullptr);
            } else if(d - 1 == 1) {
                root->left = new TreeNode(v, root->left, nullptr);
                root->right = new TreeNode(v, nullptr, root->right);
            } else {
                addOneRow(root->left, v, d - 1);
                addOneRow(root->right, v, d - 1);
            }
        }
        return root;
    }
};