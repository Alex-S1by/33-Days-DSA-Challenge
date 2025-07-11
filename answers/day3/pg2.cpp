

class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> mps;

        int i = 0;
        while (i < s.size()) {
            char ch = s[i];
            int start = i;

            // Find the end of the current block of same characters
            while (i < s.size() && s[i] == ch) {
                i++;
            }

            int len = i - start;

            // For "aaaa", len = 4
            // So we add:
            // "a" -> 4 times, "aa" -> 3 times, "aaa" -> 2, "aaaa" -> 1
            for (int l = 1; l <= len; l++) {
                mps[{ch, l}] += len - l + 1;
            }
        }

        int ans = -1;
        for (auto &x : mps) {
            if (x.second >= 3) {
                ans = max(ans, x.first.second);
            }
        }

        return ans;
    }
};
