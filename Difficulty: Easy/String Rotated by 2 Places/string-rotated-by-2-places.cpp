//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isRotated(string& s1, string& s2) {
        int n = s1.length();
        if (n != s2.length() || n < 2) return false;
        string anticlockwise = s1.substr(2) + s1.substr(0, 2);
        string clockwise = s1.substr(n - 2) + s1.substr(0, n - 2);
        return (s2 == anticlockwise || s2 == clockwise);
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        string b;
        cin >> s >> b;
        cin.ignore();
        Solution obj;
        cout << (obj.isRotated(s, b) == 0 ? "false" : "true") << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends