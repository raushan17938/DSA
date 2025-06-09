class Solution {
public:
    int findKthNumber(int n, int k) {
    
        return dfs(k, 1, to_string(n), false, 0);
    }

    int dfs(int t, int l, string r, bool zero, int ans) {
       
        if (t == 0) {
       
            return ans;
        }

        int x = zero ? 0 : 1;
        int count = 0;
        
        for(; x <= 9; x++) {
            int tmp = startWith(l, r, x);
       
            if (count + tmp >= t) {
             
                string right;
                if (r.length() == 1) {
                    right = "1";
                } else {
                    if (x == (r[0] - '0')) {
                        right = string(r.begin() + 1, r.end());
                    } else {
                        if (x < (r[0] - '0')) {
                            right = to_string(int(pow(10, r.length() - 1) - 1));
                        } else {
                            right = to_string(int(pow(10, r.length() - 2) - 1));
                        }
                    }
                }
                return dfs(t - count - 1, 0, right, true, ans * 10 + x);
            }
            count += tmp;
        }

        return -1;
    }

    int startWith(int l, string tmp, int x) {
        int r = stoi(tmp);
      
        int count = 0;
        int base = 1;

        for(int i = 0; i < tmp.length() - 1; i++) {
            count += base;
            base *= 10;
        }

        if (x == (tmp[0] - '0')) {
      
            count += (tmp.length() == 1 ? 0 : stoi(string(tmp.begin() + 1, tmp.end()))) + 1;
        } else if (x < (tmp[0] - '0')) count += base;

        return count;
    }

    int check(int n, int k) {
        vector<string> v;
        for(int i = 1; i <= n; i++)
            v.push_back(to_string(i));
        sort(v.begin(), v.end());
        return stoi(v[k-1]);
    }
};