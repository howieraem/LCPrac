class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        for (auto &num : pushed) {
            pushed[i++] = num;
            while (i && pushed[i - 1] == popped[j]) {
                --i, ++j;
            }
        }
        return i == 0;
    }
};
