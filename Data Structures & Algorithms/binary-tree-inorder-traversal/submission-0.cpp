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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;

        // auto recurse = [&](auto &self, TreeNode *node){
        //     if(node == nullptr) return;

        //     self(self, node->left);
        //     inorder.push_back(node->val);
        //     self(self, node->right);
        // };

        // recurse(recurse, root);

        stack<TreeNode *> st;
        TreeNode *curr = root;

        while(!st.empty() || curr != nullptr){
            while(curr != nullptr){
                st.push(curr);
                curr = curr->left;
            }

            TreeNode *inLine = st.top(); st.pop();
            inorder.push_back(inLine->val);
            curr = inLine->right;
        }

        return inorder;
    }
};