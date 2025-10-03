class Solution {
public:
    vector<string> possibleWords(vector<int> &arr) {
        vector<string> res = {""};
        string keys[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int d : arr) {
            if (d < 2 || d > 9) continue;
            vector<string> temp;
            for (string &s : res)
                for (char c : keys[d])
                    temp.push_back(s + c);
            res = move(temp);
        }
        return res;
    }
};