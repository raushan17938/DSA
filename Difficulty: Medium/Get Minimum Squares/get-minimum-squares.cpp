class Solution {
public:
    int minSquares(int n) {
        if(int s = sqrt(n); s * s == n) return 1;
        for(int i = 1; i * i <= n; i++)
            if(int r = sqrt(n - i * i); r * r == n - i * i) return 2;
        while(n % 4 == 0) n /= 4;
        return n % 8 == 7 ? 4 : 3;
    }
};