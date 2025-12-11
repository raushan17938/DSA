class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        long long m = (long long)arr.size();
        if (m == 0) return {0}; 
        long long disc = 1 + 8*m;
        long long s = (long long)floor(sqrt((long double)disc));
        if (s*s != disc) return {}; 
        long long n = (1 + s) / 2;
        if (n*(n-1)/2 != m) return {};

        if (n == 2) {
           
            long long r0 = 0;
            long long r1 = arr[0];
            return { (int)r0, (int)r1 };
        }

       
        long long sum0 = arr[0];
        long long sum1 = arr[1];
        long long sumn_1 = arr[n-1];

        long long numerator = sum0 + sum1 - sumn_1;
        if (numerator % 2 != 0) return {}; 
        long long r0 = numerator / 2;

        vector<long long> resLL(n);
        resLL[0] = r0;
        for (long long i = 1; i < n; ++i) {
            long long idx = i - 1;
            if (idx < 0 || idx >= m) return {};
            resLL[i] = (long long)arr[idx] - r0;
        }

        vector<long long> gen;
        gen.reserve(m);
        for (long long i = 0; i < n; ++i)
            for (long long j = i + 1; j < n; ++j)
                gen.push_back(resLL[i] + resLL[j]);

        if (gen.size() != (size_t)m) return {};
        for (size_t i = 0; i < gen.size(); ++i)
            if (gen[i] != (long long)arr[i]) return {};

        vector<int> res;
        res.reserve(n);
        for (long long x : resLL) res.push_back((int)x);
        return res;
    }
};
