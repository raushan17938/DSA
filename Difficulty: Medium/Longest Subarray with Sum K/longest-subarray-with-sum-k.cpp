//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumMap; // To store the first occurrence of each prefix sum
        int maxLength = 0;
        int currentSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            currentSum += arr[i]; 


            if (currentSum == k) {
                maxLength = i + 1;
            }

            
            if (prefixSumMap.find(currentSum - k) != prefixSumMap.end()) {
                maxLength = max(maxLength, i - prefixSumMap[currentSum - k]);
            }

            
            if (prefixSumMap.find(currentSum) == prefixSumMap.end()) {
                prefixSumMap[currentSum] = i;
            }
        }

        return maxLength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends