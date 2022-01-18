class Solution {
public:
    int strToInt(string str) {
        const int N = str.size();
        if (!N)  return 0;
        const int MAX = INT_MAX / 10;
        int ans = 0;
        int i = 0;
        while (str[i] == ' ') {
            // string with pure spaces
            if (++i == N)  return 0;
        }
        const int SIGN = str[i] == '-' ? -1 : 1;
        i += (str[i] == '-' || str[i] == '+');
        while (i < N) {
            if (str[i] < '0' || str[i] > '9')  break;
            if (ans > MAX || (ans == MAX && str[i] > '7')) {
                // handle overflow cases
                return SIGN == 1 ? INT_MAX : INT_MIN;
            }
            ans *= 10;
            ans += (str[i] - '0');
            ++i;
        }
        return SIGN * ans;
    }
};
