class Solution {
public:
    string reverseLeftWords(string s, int n) {
        // If n can be greater than len(s), do n %= len(s)

        // Method 1, fastest
        // return s.substr(n) + s.substr(0, n);

        // Method 2, less memory allocations than method 1, as substr() copies characters
        s += s;
        return s.substr(n, s.size() >> 1);
    }
};
