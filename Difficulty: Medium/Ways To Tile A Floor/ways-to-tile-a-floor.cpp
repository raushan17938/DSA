class Solution {
  public:
    int numberOfWays(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        
        long long a = 1;
        long long b = 2;
        long long c = 0;
        
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        
        return (int)b;
    }
};