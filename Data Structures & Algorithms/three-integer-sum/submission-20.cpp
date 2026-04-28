class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> sol;
        vector<int> abc = nums;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > 0) break;
            int L = i + 1;
            int R = nums.size() - 1;

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            while (L < R)
            {
                int res = nums[L] + nums[i] + nums[R];

                if (res < 0) L++;
                else if (res > 0) R--;
                else 
                {
                    sol.push_back({nums[L], nums[i], nums[R]});
                    L++;
                    R--;
                    while (L < R && nums[L] == nums[L - 1]) {
                        L++;
                    }
                }
            }
        }

        return sol;
    }
};
