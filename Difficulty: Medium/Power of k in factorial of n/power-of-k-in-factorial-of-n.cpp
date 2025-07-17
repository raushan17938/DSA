class Solution {
public:
    int maxKPower(int n, int k) {
        int ans = INT_MAX;
        if (k % 2 == 0) {
            int twos = __builtin_ctz(k);
            k >>= twos;
            int leg = n - __builtin_popcount(n);
            ans = min(ans, leg / twos);
        }
        for (int i = 3; i * i <= k; i += 2) {
            if (k % i == 0) {
                int exp = 0;
                while (k % i == 0) k /= i, exp++;
                int leg = 0;
                for (int p = i; p <= n; p *= i) leg += n / p;
                ans = min(ans, leg / exp);
            }
        }
        if (k > 1) {
            int leg = 0;
            for (int p = k; p <= n; p *= k) leg += n / p;
            ans = min(ans, leg);
        }
        return ans;
    }
};