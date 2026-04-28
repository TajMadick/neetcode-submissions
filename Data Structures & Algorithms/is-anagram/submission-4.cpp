class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> hashmapS;
        unordered_map<char, int> hashmapT;

        int length = s.length();

        for (int i = 0; i < length; i++)
        {
            hashmapS[s[i]]++;
            hashmapT[t[i]]++;
        }

        return hashmapS == hashmapT;
    }
};
