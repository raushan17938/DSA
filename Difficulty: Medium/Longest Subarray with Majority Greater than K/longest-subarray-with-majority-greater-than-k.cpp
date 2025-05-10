//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
 public:
    int longestSubarray(vector<int>& a, int k) {
        unordered_map<int, int> m;
        int s = 0, r = 0;
        for (int i = 0; i < a.size(); ++i) {
            s += a[i] > k ? 1 : -1;
            if (s > 0) r = i + 1;
            else if (m.count(s - 1)) r = max(r, i - m[s - 1]);
            m.insert({s, i});
        }
        return r;
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends