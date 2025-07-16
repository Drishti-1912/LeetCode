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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;  //we need to return a vector

        if(root==NULL) return ans;  //base case

        stack<TreeNode*> st;        //using stack
        st.push(root);
        
        while(!st.empty()){

            root=st.top();           //top wala element pop krte rho
            st.pop();

            ans.push_back(root->val);

            if(root->right!=nullptr){  //right
                st.push(root->right);
            }
            if(root->left!=nullptr){   //then left
                st.push(root->left);
            }
        }
    return ans;
    }
};