// User function template for C++
class Solution {
 public:
    string findSum(string &s1, string &s2) {
        if (s2.length() > s1.length())
            swap(s1, s2);

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        string result = "";
        int carry = 0;

        for (int i = 0; i < s1.length(); ++i) {
            int digit1 = s1[i] - '0';
            int digit2 = (i < s2.length()) ? s2[i] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            result += (sum % 10) + '0';
            carry = sum / 10;
        }

        if (carry)
            result += carry + '0';

        reverse(result.begin(), result.end());

        int i = 0;
        while (i < result.length() - 1 && result[i] == '0') {
            ++i;
        }

        return result.substr(i);
    }
};