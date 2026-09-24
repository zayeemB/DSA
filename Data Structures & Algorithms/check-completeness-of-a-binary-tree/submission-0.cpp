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
    bool isCompleteTree(TreeNode* root) {
        auto depth = [](auto &self, TreeNode *node)->int{
            if(node == nullptr)
                return 0;
            
            int left = self(self, node->left);
            int right = self(self, node->right);

            return 1 + max(left, right);
        };

        int maxLevel = depth(depth, root);

        queue<TreeNode *> q;

        if(root != nullptr) q.push(root);
        int level = 1;

        while(!q.empty() && level < maxLevel){
            int levelSize = q.size();

            for(int i = 0; i < levelSize; i++){
                TreeNode *curr = q.front(); q.pop();

                if(level < maxLevel-1 && (curr->left == nullptr || curr->right == nullptr))
                    return false;

                q.push(curr->left);
                q.push(curr->right);
            }

            if(q.size() != 0 && q.size() != (1 << level) && level != maxLevel-1)
                return false;
            

            if(level == maxLevel-1){
                while(!q.empty() && q.front() != nullptr)
                    q.pop();
                
                while(!q.empty() && q.front() == nullptr)
                    q.pop();
                
                return q.empty();
            }

            level++;
        }

        return true;
    }
};