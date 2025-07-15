class Solution {
public:
    bool divby13(string &s) {
        int r = 0;
        const char* p = s.c_str();
        while (*p) r = (r * 10 + *p++ - '0') % 13;
        return !r;
    }
};