class Solution {
public:
    // Idea: sort the numbers such that the concatenated number is the smallest.
    // Comparator rule: string x > string y if string (x + y) > string (y + x)
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto &n : nums) {
            strs.push_back(to_string(n));
        }

        // Solution with std::sort and the defined comparator (slower)
        // sort(strs.begin(), strs.end(), [](string &x, string &y) { return x + y < y + x; });

        // Solution based on quick sort
        quickSort(strs, 0, strs.size() - 1);

        string res;
        for (auto &s : strs) {
            res.append(s);
        }
        return res;
    }

private:
    void quickSort(vector<string> &strs, int l, int r) {
        if (l >= r)  return;
        int i = l, j = r;
        while (i < j) {
            while (strs[j] + strs[l] >= strs[l] + strs[j] && i < j)  --j;
            while (strs[i] + strs[l] <= strs[l] + strs[i] && i < j)  ++i;
            swap(strs[i], strs[j]);
        }
        swap(strs[i], strs[l]);
        quickSort(strs, l, i - 1);
        quickSort(strs, i + 1, r);
    }
};
