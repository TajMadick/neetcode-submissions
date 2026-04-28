class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int startSize = nums.size();

        std::set<int> unique(nums.begin(), nums.end()); 

        if (unique.size() == startSize)
        {
            return false;
        }

        return true;
    }
};