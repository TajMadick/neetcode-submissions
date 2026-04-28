class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> hashmap;

        for (int i = 0; i < nums.size(); i++)
        {
            if (hashmap.count(nums[i]) > 0)
            {
                return true;
            }
            else
            {
                hashmap.insert({nums[i], nums[i]});
            }
        }
        return false;
    }
};