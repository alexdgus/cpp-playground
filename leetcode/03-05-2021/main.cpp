/* Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array. */

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
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sums;
        std::queue<TreeNode*> q;
        if(root) {
            q.push(root);
        }

        int levelSize = q.size();

        while(!q.empty()) {
            double sum = 0;
            for(int i = 0; i < levelSize; i++) {
                sum += q.front()->val;
                if(q.front()->left) {
                    q.push(q.front()->left);
                }
                if(q.front()->right) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            sums.push_back(sum / levelSize);
            levelSize = q.size();
        }
        return sums;
    }
};