/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    int distCandy(Node* root) {
        int moves = 0;
        function<int(Node*)> dfs = [&](Node* n) {
            if (!n) return 0;
            int bal = n->data - 1 + dfs(n->left) + dfs(n->right);
            moves += abs(bal);
            return bal;
        };
        dfs(root);
        return moves;
    }
};