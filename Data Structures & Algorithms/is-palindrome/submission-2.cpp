class Solution {
public:
bool isPalindrome(string s) {
    for (int L = 0, R = s.size()-1; L < R; L++, R--)
    {
        // kleiner als 65 oder zwischen 91 und 96 oder größer als 122
        while (s[L] < '0' || s[L] > '9' && s[L] < 'A' || s[L] > 'Z' && s[L] < 'a' || s[L] > 'z') L++;
        while (s[R] < '0' || s[R] > '9' && s[R] < 'A' || s[R] > 'Z' && s[R] < 'a' || s[R] > 'z') R--;
        
        if (L > R) break;
        
        if (s[L] >= 'A' && s[L] <= 'Z') s[L] += 32;
        if (s[R] >= 'A' && s[R] <= 'Z') s[R] += 32;
    
        if (s[L] != s[R]) return false;
    }

    return true;
}
};
