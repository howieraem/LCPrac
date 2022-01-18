#include <string>
#include <vector>

using namespace std;

// Need to consider extremely large numbers which might not be properly represented by uint64.
// Thus, it is better to treat numbers as strings.
class Solution {
private:
	vector<int> res;
	string s;
	int end;

public:
	vector<int> printNumbers(int n) {
		s.resize(n, '0');	// set s to '000...000', n zeros in total
		end = n;
		return res;
	}

	void dfs(int s_idx) {
		if (s_idx == end) {
			postProcess();
			return;
		}
		// Enumerate all combinations of 0-9 in n digits
		for (int i = 0; i <= 9; ++i) {
			s[s_idx] = i + '0';
			dfs(s_idx + 1);
		}
	}

	// Removes trailing zeros
	void postProcess() {
		int ptr = 0;
		while (ptr < s.size() && s[ptr] == '0')  ++ptr;
		if (ptr != s.size()) {
			res.push_back(stoi(s.substr(ptr)));
		}
	}
};