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
    TreeNode* convertBST(TreeNode* root) {
        if(root != nullptr) {
            traverseBST(root, 0);
        }
        return root;
    }
    
    int traverseBST(TreeNode* node, int sum) {
        int leftSum = 0;
        int rightSum = 0;

        if(node->right != nullptr) {
            rightSum = traverseBST(node->right, sum);
        }

        if(node->left != nullptr) {
            leftSum = traverseBST(node->left, node->val + rightSum + sum);
        }
        int nodeVal = node->val;
        node->val += rightSum + sum;
        return nodeVal + leftSum + rightSum;
    }
};
