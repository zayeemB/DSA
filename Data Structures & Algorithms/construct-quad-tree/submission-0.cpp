/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    vector<vector<int>> splice(const vector<vector<int>> &arr, int xs, int xe, int ys, int ye){
        vector<vector<int>> new_array;

        new_array.reserve(xe - xs);

        for(int i = xs; i < xe; i++){
            vector<int> row(arr[i].begin()+ys, arr[i].begin()+ye);
            new_array.push_back(row);
        }

        return new_array;
    }

    bool isGridSame(const vector<vector<int>> &arr){
        int n = arr.size();
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n-1; j++){
                if(arr[i][j] != arr[i+1][j] || arr[i][j] != arr[i][j+1]) return false;
            }
        }
        return true;
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        if(n == 1){
            Node* new_node = new Node(grid[n-1][n-1], 1);
            return new_node;
        }
        else if(isGridSame(grid)){
            Node* new_node = new Node(grid.back().back(), 1);
            return new_node;
        }
        else{
            int mid = n/2;
            
            vector<vector<int>> top_left = splice(grid, 0, mid, 0, mid);
            vector<vector<int>> top_right = splice(grid, 0, mid, mid, n);
            vector<vector<int>> bottom_left = splice(grid, mid, n, 0, mid);
            vector<vector<int>> bottom_right = splice(grid, mid, n, mid, n);

            Node* new_node = new Node(1, 0);
            
            new_node->topLeft = construct(top_left);
            new_node->topRight = construct(top_right);
            new_node->bottomLeft = construct(bottom_left);
            new_node->bottomRight = construct(bottom_right);

            return new_node;
        }
    }
};