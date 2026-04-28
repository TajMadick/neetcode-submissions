class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        unordered_map<int, unordered_map<char, int>> hashmaps;
        
        for (int i = 0; i < strs.size(); i++)
        {
            unordered_map<char, int> letters;
            for (char character: strs[i])
            {
                letters[character]++;
            }

            hashmaps.insert({i, letters});
        }

        vector<vector<string>> groups;

        unordered_set<int> usedIndizes;

        for (int i = 0; i < hashmaps.size(); i++)
        {
            if (!usedIndizes.count(i))
            {
                vector<string> group;
                group.push_back(strs[i]);
                usedIndizes.insert(i);

                for (int j = i + 1; j < hashmaps.size(); j++)
                {
                    if (hashmaps[j] == hashmaps[i] && !usedIndizes.count(j))
                    {
                        group.push_back(strs[j]);
                        usedIndizes.insert(j);
                    }
                }
            groups.push_back(group);
            }
        }

        sort(groups.begin(), groups.end());
        return groups;
    }
};
