/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
public:
    int getMaxSum(Node* root) {
        function<pair<int,int>(Node*)> dfs = [&](Node* node) -> pair<int,int> {
            if (!node) return {0, 0};
            auto [li, le] = dfs(node->left);
            auto [ri, re] = dfs(node->right);
            return {node->data + le + re, max(li, le) + max(ri, re)};
        };
        auto [inc, exc] = dfs(root);
        return max(inc, exc);
    }
};