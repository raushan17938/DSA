class Solution {
  public:
    vector<int> subsetXOR(int n) {
        int all_xor = 0;
        for (int i = 1; i <= n; i++) {
            all_xor ^= i;
        }

        vector<int> res;
        
        if (all_xor == n) {
            for (int i = 1; i <= n; i++) {
                res.push_back(i);
            }
        } 

        else {
            int x = all_xor ^ n;
            for (int i = 1; i <= n; i++) {
                if (i != x) {
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};