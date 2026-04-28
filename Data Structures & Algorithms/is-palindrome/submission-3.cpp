class Solution {
public:
bool isPalindrome(string s) {
    for (int L = 0, R = s.size()-1; L < R; L++, R--)
    {
        while (L < R && !isAlpha(s[L])) L++;
        while (L < R && !isAlpha(s[R])) R--;
        
        if (s[L] >= 'A' && s[L] <= 'Z') s[L] += 32;
        if (s[R] >= 'A' && s[R] <= 'Z') s[R] += 32;
    
        if (s[L] != s[R]) return false;
    }

    return true;
}

bool isAlpha(char c)
{
    if (c >= '0' && c <= '9' || 
        c >= 'A' && c <= 'Z' || 
        c >= 'a' && c <= 'z') return true;
    
    return false;
}
};
