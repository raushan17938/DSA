//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
         unordered_map<int, int> prefixSumMap; 
        int maxLength = 0;                   
        int sum = 0;                         
        
        for (int i = 0; i < arr.size(); i++) {
            
            sum += (arr[i] == 0) ? -1 : 1;

            if (sum == 0) {
                maxLength = i + 1;
            }

    
            if (prefixSumMap.find(sum) != prefixSumMap.end()) {
                maxLength = max(maxLength, i - prefixSumMap[sum]);
            } else {
                
                prefixSumMap[sum] = i;
            }
        }
        
        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends