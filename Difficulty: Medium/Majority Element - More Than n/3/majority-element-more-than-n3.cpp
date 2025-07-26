class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size(), a = 0, b = 1, ca = 0, cb = 0;
        for (int x : arr) {
            if (x == a) ca++;
            else if (x == b) cb++;
            else if (!ca) a = x, ca = 1;
            else if (!cb) b = x, cb = 1;
            else ca--, cb--;
        }
        ca = cb = 0;
        for (int x : arr) {
            if (x == a) ca++;
            else if (x == b) cb++;
        }
        vector<int> res;
        if (ca > n / 3) res.push_back(a);
        if (cb > n / 3 && a != b) res.push_back(b);
        sort(res.begin(), res.end());
        return res;
    }
};