class Solution {
    #define ll long long
public:
    long long flowerGame(int n, int m) {
        ll count = 0;

        int odds_in_n = (n+1)/2;
        int even_in_m = m/2;
        count += (1LL * odds_in_n * even_in_m);

        int even_in_n = n/2;
        int odds_in_m = (m+1)/2;
        count += (1LL * even_in_n * odds_in_m);

        return count;
    }
};