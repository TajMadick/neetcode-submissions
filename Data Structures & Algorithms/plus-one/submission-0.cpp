class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> solution(digits.size(), 0);
       for (int i = 0; i < digits.size(); i++)
       {
            int position = digits.size() - 1 - i;
            int digit = digits[position];
            if (digit + carry < 10)
            {
                digit += carry;
                carry = 0;
            }
            else
            {
                digit = 0;
            }

            solution[position] = digit;
       }

       if (carry == 1)
       {
            solution.insert(solution.begin(), carry);
       }

       return solution;
    }
};
