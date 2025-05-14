//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int isValid(string& s) {
        stringstream ss(s);
        string part;
        int count = 0;

        while (getline(ss, part, '.')) {
           
            if (part.empty() || part.length() > 3)
                return 0;

      
            for (char c : part) {
                if (!isdigit(c))
                    return 0;
            }

           
            if (part.length() > 1 && part[0] == '0')
                return 0;

      
            int value = stoi(part);
            if (value < 0 || value > 255)
                return 0;

            count++;
        }

 
        return count == 4 ? 1 : 0;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends