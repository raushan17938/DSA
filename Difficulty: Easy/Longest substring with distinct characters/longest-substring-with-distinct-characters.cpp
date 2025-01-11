//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        unordered_map<char, int> charIndexMap; 
        int maxLength = 0; 
        int start = 0; 

        for (int end = 0; end < s.size(); end++) {
            char currentChar = s[end];

            
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
                
                start = charIndexMap[currentChar] + 1;
            }

            
            charIndexMap[currentChar] = end;

            
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends