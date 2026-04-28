class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hm;
        priority_queue<pair<int,int>> pq;
        vector<int> sol;

        for (int num: nums)
        {
            hm[num]++;
        }

        for (auto num: hm)
        {
            pq.push({num.second, num.first});
        }

        while (!pq.empty() && k > 0)
        {
            sol.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return sol;
    }
};
