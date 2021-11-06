class Solution {
public:
    vector<string> permutation(string s) {
        str = s;
        dfs(0);
        return res;
    }

private:
    string str;
    vector<string> res;

    void dfs(int cur) {
        if (cur == str.size() - 1) {
            string ret = str; // make a copy
            res.push_back(ret);
            return;
        }
        int vis = 0;
        for (int i = cur; i < str.size(); ++i) {
            if ((vis >> (str[i] - 'a')) & 1)  continue;  // avoid producing duplicates
            vis |= (1 << (str[i] - 'a'));
            swap(str[i], str[cur]);
            dfs(cur + 1);
            swap(str[cur], str[i]);
        }
    }
};