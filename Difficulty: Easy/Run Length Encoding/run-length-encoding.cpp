class Solution {
  public:
    string encode(string s) {
        string result = "";
        int n = s.length();

        for (int i = 0; i < n; ) {
            char current = s[i];
            int count = 0;

          
            while (i < n && s[i] == current) {
                count++;
                i++;
            }


            result += current + to_string(count);
        }

        return result;
    }
};
