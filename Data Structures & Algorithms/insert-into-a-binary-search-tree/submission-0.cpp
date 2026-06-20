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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        auto recurse = [](auto &self, TreeNode *node, int val)->void{
            if(val <= node->val){
                if(node->left == nullptr){
                    node->left = new TreeNode(val);
                }
                else{
                    self(self, node->left, val);
                }
            }
            else{
                if(node->right == nullptr){
                    node->right = new TreeNode(val);
                }
                else{
                    self(self, node->right, val);
                }
            }
        };

        if(root == nullptr){
            return new TreeNode(val);
        }
        else{
            recurse(recurse, root, val);
        }
        return root;
    }
};