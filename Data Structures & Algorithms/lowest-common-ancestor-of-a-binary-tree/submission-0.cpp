/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> arr;

        auto traverse = [&](auto &self, TreeNode *node){
            if(node == nullptr)
                return;

            self(self, node->left);
            arr.push_back(node->val);
            self(self, node->right);
        };

        traverse(traverse, root);

        unordered_map<int, int> indices;

        for(int i = 0; i < arr.size(); i++){
            indices[arr[i]] = i;
        }

        auto find = [&](auto &self, TreeNode *root, TreeNode *p, TreeNode *q)->TreeNode *{
            int val = root->val;

            if((val == p->val || val == q->val)
                || (indices[p->val] < indices[val] && indices[q->val] > indices[val])
                || (indices[p->val] > indices[val] && indices[q->val] < indices[val])
            ){
                return root;
            }
            else if(indices[p->val] < indices[val] && indices[q->val] < indices[val]){
                return self(self, root->left, p, q);
            }
            else{
                return self(self, root->right, p, q);
            }
        };

        return find(find, root, p, q);
    }
};