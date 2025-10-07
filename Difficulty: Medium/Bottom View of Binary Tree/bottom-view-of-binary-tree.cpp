/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    vector<int> bottomView(Node* root) {
        if (!root) return {};
        map<int, int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();
            m[hd] = node->data;
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        vector<int> res;
        for (auto& [k, v] : m) res.push_back(v);
        return res;
    }
};