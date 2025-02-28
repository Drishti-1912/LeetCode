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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> finalAns;
        if (root == nullptr) {
            return finalAns;
        }
        q.push(root);
        while (!q.empty()) {
            int levels = q.size();
            vector<int> subLevels;
            for (int i = 0; i < levels; i++) {
                if (q.front()->left != nullptr) {
                    q.push(q.front()->left);
                }
                if (q.front()->right != nullptr) {
                    q.push(q.front()->right);
                }
                subLevels.push_back(q.front()->val);
                q.pop();
            }
            finalAns.push_back(subLevels);
        }
        return finalAns;
    }
    
};