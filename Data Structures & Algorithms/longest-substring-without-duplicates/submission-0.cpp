class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int length = 0;

        int L = 0;

        for (int R = 0; R < s.size(); R++)
        {
            while (seen.count(s[R]))
            {
                seen.erase(s[L]);
                L++;
            }

            length = max(length, R-L + 1);
            seen.insert(s[R]);
        }

        return length;
    }
};
