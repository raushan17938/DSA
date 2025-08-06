class Solution {
public:
    int romanToDecimal(string s) {
        int vals[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string syms[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int res = 0, i = 0;
        for (int j = 0; j < 13; j++) {
            while (i + syms[j].length() <= s.length() && s.substr(i, syms[j].length()) == syms[j]) {
                res += vals[j];
                i += syms[j].length();
            }
        }
        return res;
    }
};