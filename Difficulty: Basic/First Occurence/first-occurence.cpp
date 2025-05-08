//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to locate the occurrence of the string x in the string s.
class Solution {
  public:
    int firstOccurence(string &txt, string &pat) {
         int n = txt.length();
        int m = pat.length();

       \
        for (int i = 0; i <= n - m; i++) {
            int j;

         
            for (j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }

         
            if (j == m) {
                return i; 
            }
        }

        return -1; 
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a;
        string b;

        cin >> a;
        cin >> b;
        Solution ob;
        cout << ob.firstOccurence(a, b) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends