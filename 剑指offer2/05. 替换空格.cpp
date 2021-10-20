class Solution {
public:
    string replaceSpace(string s) {
        // string ans(s.length() * 3, ' ');
        // int p = 0;
        string ans;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                // ans[p++] = '%';
                // ans[p++] = '2';
                // ans[p++] = '0';
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            } else {
                // ans[p++] = s[i];
                ans.push_back(s[i]);
            }
        }
        // return ans.substr(0, p);
        return ans;
    }
};