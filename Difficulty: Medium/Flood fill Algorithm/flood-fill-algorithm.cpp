//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size(), color = image[sr][sc];
        if (color == newColor) return image;
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        image[sr][sc] = newColor;
        int dirs[5] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second; q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i], ny = y + dirs[i+1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && image[nx][ny] == color) {
                    image[nx][ny] = newColor;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends