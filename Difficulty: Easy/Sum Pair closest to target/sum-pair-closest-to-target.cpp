//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        if (n < 2) return {}; 

        sort(arr.begin(), arr.end()); 

        int left = 0, right = n - 1;
        int closestSum = INT_MAX;
        int maxAbsDiff = INT_MIN;
        vector<int> result;

        while (left < right) {
            int sum = arr[left] + arr[right];
            
            if (abs(sum - target) < abs(closestSum - target) || 
                (abs(sum - target) == abs(closestSum - target) && (arr[right] - arr[left] > maxAbsDiff))) {
                closestSum = sum;
                maxAbsDiff = arr[right] - arr[left];
                result = {arr[left], arr[right]};
            }

            if (sum < target) {
                ++left; 
            } else {
                --right; 
            }
        }

        return result;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends