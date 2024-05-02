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
public:
    Node* constructTree(int x, int y, int n, const vector<vector<int>>& grid) {
        bool isLeaf = true;
        int val = grid[x][y];
        for (int i = 0; i < n && isLeaf; ++i) {
            for (int j = 0; j < n && isLeaf; ++j) {
                if (val != grid[x+i][y+j]) isLeaf = false;
            }
        }
        if (isLeaf) return new Node(val, true);

        int m = n >> 1;
        Node* topLeft = constructTree(x, y, m, grid);
        Node* topRight = constructTree(x, y + m, m, grid);
        Node* bottomLeft = constructTree(x + m, y, m, grid);
        Node* bottomRight = constructTree(x + m, y + m, m, grid);
        return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return constructTree(0, 0, n, grid);
    }
};
