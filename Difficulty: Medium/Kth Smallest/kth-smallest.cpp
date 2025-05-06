//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Helper function to partition the array
    int partition(vector<int>& arr, int left, int right) {
        int pivot = arr[right];
        int i = left;

        for (int j = left; j < right; j++) {
            if (arr[j] <= pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[right]);
        return i;
    }

    // QuickSelect recursive function
    int quickSelect(vector<int>& arr, int left, int right, int k) {
        if (left <= right) {
            int pivotIndex = partition(arr, left, right);

            if (pivotIndex == k - 1)
                return arr[pivotIndex];
            else if (pivotIndex > k - 1)
                return quickSelect(arr, left, pivotIndex - 1, k);
            else
                return quickSelect(arr, pivotIndex + 1, right, k);
        }
        return -1; // Invalid case
    }

    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        return quickSelect(arr, 0, arr.size() - 1, k);
    }
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends