class Solution {
public:
    int findMin(vector<int> &nums) {
        int start, end, mid, pivot;
        start = 0;
        end = nums.size()-1;
        pivot = end;

        while (end >= start)
        {
            mid = start + (end - start) / 2;

            if (nums[mid] < nums[pivot])
            {
                pivot = mid;
                end = mid - 1;
            }
            else if (nums[mid] > nums[pivot])
            {
                start = mid + 1;
            }
            else break;
        }

        return nums[pivot];

        /*
        while (end > start)
        {
            mid = start + (end - start) / 2;
            
            if (nums[mid] > nums[end]) start = mid + 1;
            else if (nums[mid] > nums[start]) end = mid - 1;
            else return nums[mid];
        }

        return nums[start];
        */
    }
};
