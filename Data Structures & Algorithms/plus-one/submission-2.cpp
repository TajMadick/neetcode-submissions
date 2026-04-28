class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;

       for (int i = digits.size() - 1; i >= 0; i--)
       {
            int digit = digits[i];
            if (digit + carry < 10)
            {
                digit += carry;
                carry = 0;
            }
            else
            {
                digit = 0;
            }

            digits[i] = digit;
            if (carry == 0) return digits;
       }

       if (carry == 1)
       {
            digits.insert(digits.begin(), carry);
       }

       return digits;
    }
};
