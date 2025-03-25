//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int countWays(string &s) {
        int n = s.size();
        vector<vector<int>> dpT(n, vector<int>(n, 0)), dpF(n, vector<int>(n, 0));
        for (int i = 0; i < n; i += 2) dpT[i][i] = (s[i] == 'T'), dpF[i][i] = (s[i] == 'F');
        for (int len = 2; len < n; len += 2) 
            for (int i = 0; i < n - len; i += 2) {
                int j = i + len;
                for (int k = i + 1; k < j; k += 2) {
                    int lt = dpT[i][k - 1], lf = dpF[i][k - 1], rt = dpT[k + 1][j], rf = dpF[k + 1][j];
                    if (s[k] == '&') dpT[i][j] += lt * rt, dpF[i][j] += lt * rf + lf * rt + lf * rf;
                    else if (s[k] == '|') dpT[i][j] += lt * rt + lt * rf + lf * rt, dpF[i][j] += lf * rf;
                    else dpT[i][j] += lt * rf + lf * rt, dpF[i][j] += lt * rt + lf * rf;
                }
            }
        return dpT[0][n - 1];
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends