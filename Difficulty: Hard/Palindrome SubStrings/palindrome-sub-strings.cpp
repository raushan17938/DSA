class Solution {
public:
    int countPS(string &s) {
        int n = s.size(), ans = 0;
        auto go=[&](int l,int r){
            while(l>=0&&r<n&&s[l--]==s[r++]) ans++;
        };
        for(int i=0;i<n;i++) go(i-1,i+1), go(i,i+1);
        return ans;
    }
};