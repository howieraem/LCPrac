class Solution {
public:
    /** Solution based on quick sort/select. 
      * Usually the fastest if array numbers are random. 
      */
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (!k || !arr.size())  return {};  // empty vector (since C++11)
        return quickSearch(arr, 0, arr.size() - 1, k - 1);
    }

private:
    static vector<int> quickSearch(vector<int>& arr, int l, int r, int k) {
        int j = partition(arr, l, r);
        if (j == k) {
            // Below (since C++11) is equivalent to `Arrays.copyOf(arr, j + 1)` in Java 
            // and `arr[:j + 1]` in Python. 
            return {arr.begin(), arr.begin() + j + 1};
        }
        return j > k ? quickSearch(arr, l, j - 1, k) : quickSearch(arr, j + 1, r, k);
    }

    static int partition(vector<int>& arr, int l, int r) {
        int v = arr[l];
        int i = l, j = r + 1;
        while (true) {
            while (++i <= r && arr[i] < v);
            while (--j >= l && arr[j] > v);
            if (i >= j)  break;
            swap(arr[i], arr[j]);
        }
        arr[l] = arr[j];
        arr[j] = v;
        return j;
    }
};