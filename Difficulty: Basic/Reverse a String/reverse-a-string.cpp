// User function Template for C++
class Solution {
  public:
    string revStr(string s) {
     
        int left = 0, right = s.length() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};
