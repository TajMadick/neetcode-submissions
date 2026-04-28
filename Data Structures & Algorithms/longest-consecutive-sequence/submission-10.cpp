class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numbers(nums.begin(), nums.end());

        int maxCount = 0;

        for (int num: numbers)
        {
            if (numbers.count(num - 1))
            {
                continue;
            }

            for (int i = num, counter = 0; ; i++)
            {
                if (numbers.count(i))
                {
                    counter ++;
                }
                else
                {
                    maxCount = max(counter, maxCount);
                    break;
                }
            }
        }

        return maxCount;
    }
};
