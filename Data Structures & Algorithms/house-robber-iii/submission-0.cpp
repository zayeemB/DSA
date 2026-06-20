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
    int rob(TreeNode* root) {

        auto recurse = [](auto &self, TreeNode *root)->pair<int, int>{
            if(root == nullptr){
                return {0,0};
            }

            pair<int,int> left = self(self, root->left);
            pair<int,int> right = self(self, root->right);

            int rob = left.second+right.second+root->val;
            int leave = max(left.first, left.second) + max(right.first, right.second);

            return {rob, leave};
        };

        pair<int,int> res = recurse(recurse, root);
        return max(res.first, res.second); 
    }
};