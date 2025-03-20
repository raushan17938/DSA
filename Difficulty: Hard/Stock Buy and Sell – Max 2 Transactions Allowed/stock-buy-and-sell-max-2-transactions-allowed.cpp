//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        if (!n) return 0;
        vector<int> l(n), r(n);
        int mn = p[0];
        for (int i = 1; i < n; i++) {
            mn = min(mn, p[i]);
            l[i] = max(l[i - 1], p[i] - mn);
        }
        int mx = p[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            mx = max(mx, p[i]);
            r[i] = max(r[i + 1], mx - p[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, l[i] + r[i]);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends