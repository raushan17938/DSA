//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    string reverseString(string& s) {
        // code here
        int n = s.length()-1;
        int i = 0;
        while(i<=n){
            swap(s[i++], s[n--]);
            
        }
        
        return s;
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
        cout << ob.reverseString(s) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends