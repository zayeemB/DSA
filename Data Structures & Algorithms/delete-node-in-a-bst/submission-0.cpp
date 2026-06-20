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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        TreeNode *dummy = new TreeNode(0, root, nullptr);
        auto find = [](auto &self, TreeNode *node, TreeNode *par, int key)->pair<TreeNode *, TreeNode *>{
            if(node == nullptr || key == node->val){
                return {par, node};
            }

            if(key < node->val){
                return self(self, node->left, node, key);
            }
            else{
                return self(self, node->right, node, key);
            }
            
        };

        pair<TreeNode*, TreeNode*> p = find(find, root, dummy, key);

        TreeNode *par = p.first;
        TreeNode *node = p.second;

        if(node == nullptr) return root;

        auto del = [](auto &self, TreeNode* node, TreeNode* par)->void{
            if(node->left == nullptr && node->right == nullptr){
                if(par->left == node) par->left = nullptr;
                if(par->right == node) par->right = nullptr;
            }
            else if(node->left == nullptr || node->right == nullptr){
                TreeNode *child = node->left == nullptr? node->right: node->left;

                if(par->left == node) par->left = child;
                if(par->right == node) par->right = child;
            }
            else{
                TreeNode *smallestRightChild = node->right;
                TreeNode *smallestRightChildPar = node;
                while(smallestRightChild->left != nullptr){
                    smallestRightChildPar = smallestRightChild;
                    smallestRightChild = smallestRightChild->left;
                }
                node->val = smallestRightChild->val;
                self(self, smallestRightChild, smallestRightChildPar);
            } 
        };

        del(del, node, par);
        return dummy->left;
    }
};