class Solution {
  public:
    string st; // String to store the result

    void printParenthesis(int i, int j, vector<vector<int>> &bracket, char &name) {
        if (i == j) {
            st += name;
            name++;
            return;
        }
        st += '(';
        printParenthesis(i, bracket[i][j], bracket, name);
        printParenthesis(bracket[i][j] + 1, j, bracket, name);
        st += ')';
    }

    string matrixChainOrder(vector<int> &arr) {
        int n = arr.size();
        
        vector<vector<int>> m(n, vector<int>(n, 0));
        
        vector<vector<int>> bracket(n, vector<int>(n, 0));

        for (int L = 2; L < n; L++) {
            for (int i = 1; i < n - L + 1; i++) {
                int j = i + L - 1;
                m[i][j] = INT_MAX;
                
                for (int k = i; k <= j - 1; k++) {
                    int q = m[i][k] + m[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    
                    if (q < m[i][j]) {
                        m[i][j] = q;
                        bracket[i][j] = k;
                    }
                }
            }
        }

        st = "";
        char name = 'A';
        printParenthesis(1, n - 1, bracket, name);
        return st;
    }
};