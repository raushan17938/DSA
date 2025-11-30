class Solution {
public:
    int countSubs(string& s) {
        int cnt = 0, n = s.length();
        struct Node { Node* c[26] = {}; };
        Node* root = new Node();
        for (int i = 0; i < n; i++) {
            Node* cur = root;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (!cur->c[idx]) {
                    cur->c[idx] = new Node();
                    cnt++;
                }
                cur = cur->c[idx];
            }
        }
        return cnt;
    }
};