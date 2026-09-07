/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *ptr = p;
        
        while(ptr->parent != nullptr){
            ptr = ptr->parent;
        }

        auto find = [&](auto &self, Node *node, Node *p, Node *q){
            if(node == nullptr || node->val == p->val || node->val == q->val){
                return node;
            }

            Node *left = self(self, node->left, p, q);
            Node *right = self(self, node->right, p, q);

            if(left != nullptr && right != nullptr)
                return node;
            
            return (left != nullptr)? left: right;
        };

        return find(find, ptr, p, q);
    }
};