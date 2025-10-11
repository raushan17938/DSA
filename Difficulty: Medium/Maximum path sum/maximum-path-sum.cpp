/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
public:
    int findMaxSum(Node *root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
    
    int dfs(Node *node, int &res) {
        if (!node) return 0;
        int l = max(0, dfs(node->left, res));
        int r = max(0, dfs(node->right, res));
        res = max(res, node->data + l + r);
        return node->data + max(l, r);
    }
};