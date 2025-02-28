class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        TreeNode* pre;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                res.push_back(curr->val);
                curr = curr->right;  // move to next right node
            } else {
                pre = curr->left;
                while (pre->right != nullptr && pre->right != curr) {  // find rightmost
                    pre = pre->right;
                }

                if (pre->right == nullptr) {
                    // establish a link back to the current node
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    // restore the tree structure
                    pre->right = nullptr;
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return res;
    }
};