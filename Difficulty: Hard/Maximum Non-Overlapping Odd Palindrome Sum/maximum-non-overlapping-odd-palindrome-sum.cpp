struct Manacher {
    vector<int> d;
    Manacher(const string &s) {
        string t = "@";
        for (char c : s) t += "#", t += c;
        t += "#$";
        int n = t.size(), l = 0, r = 0;
        d.assign(n, 0);
        for (int i = 1; i < n - 1; i++) {
            if (i < r) d[i] = min(r - i, d[l + r - i]);
            while (t[i - d[i] - 1] == t[i + d[i] + 1]) d[i]++;
            if (i + d[i] > r) l = i - d[i], r = i + d[i];
        }
    }
    int get(int i) { return d[2 * i + 2]; }
};

class Solution {
public:
    int maxSum(string s) {
        int n = s.size();
        Manacher M(s);
        vector<int> L(n), R(n);
        for (int i = 0; i < n; i++) {
            int len = M.get(i);
            L[i + len / 2] = max(L[i + len / 2], len);
            R[i - len / 2] = max(R[i - len / 2], len);
        }
        for (int i = n - 2; i >= 0; i--) L[i] = max(L[i], L[i + 1] - 2);
        for (int i = 1; i < n; i++) L[i] = max(L[i], L[i - 1]);
        for (int i = 1; i < n; i++) R[i] = max(R[i], R[i - 1] - 2);
        for (int i = n - 2; i >= 0; i--) R[i] = max(R[i], R[i + 1]);
        int ans = 1;
        for (int i = 0; i + 1 < n; i++) ans = max(ans, L[i] + R[i + 1]);
        return ans;
    }
};