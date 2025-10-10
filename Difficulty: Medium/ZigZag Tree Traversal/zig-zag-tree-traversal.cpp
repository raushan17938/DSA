/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        bool ltr = true;
        while (!q.empty()) {
            int sz = q.size();
            vector<int> lvl(sz);
            for (int i = 0; i < sz; i++) {
                Node* node = q.front();
                q.pop();
                int idx = ltr ? i : sz - 1 - i;
                lvl[idx] = node->data;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ltr = !ltr;
            res.insert(res.end(), lvl.begin(), lvl.end());
        }
        return res;
    }
};