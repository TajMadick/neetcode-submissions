class Solution {
public:
    int maxArea(vector<int>& heights) {
        int L = 0; 
        int R = heights.size() - 1;

        int maxWater = 0;

        while (L < R)
        {
            int lHeight = heights[L];
            int rHeight = heights[R];

            maxWater = max(maxWater, min(lHeight, rHeight) * (R - L));

            if (lHeight <= rHeight) L++;
            else if (rHeight < lHeight) R--;
        }

        return maxWater;
    }
};
