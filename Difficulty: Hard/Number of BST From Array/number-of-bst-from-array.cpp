class Solution {
public:
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> p(n);
        for (int i = 0; i < n; i++) p[i] = {arr[i], i};
        sort(p.begin(), p.end());
        vector<long> c(n + 1);
        c[0] = c[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) 
                c[i] += c[j] * c[i - j - 1];
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) 
            res[p[i].second] = c[i] * c[n - i - 1];
        return res;
    }
};