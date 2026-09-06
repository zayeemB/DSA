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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        
        auto traverse = [&low, &high, &sum](auto &self, TreeNode *node)->void{
            if(node == nullptr)
                return;
        
            self(self, node->left);
            if(node->val >= low && node->val <= high)
                sum += node->val;
            self(self, node->right);
        };

        traverse(traverse, root);
        
        return sum;
    }
};